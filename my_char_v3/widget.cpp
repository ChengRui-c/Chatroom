#include "widget.h"
#include "ui_widget.h"
#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QColorDialog>//用于更改颜色
#include <QProcess>//获取本机网络信息
#include <QtWidgets>//用于启动外部程序并与之通信
#include<QStandardPaths>

Widget::Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);



    //设置晶体管控件QLCDNumber能显示的位数
    ui->lcdNumber->setDigitCount(10);
    //设置显示的模式为十进制
    ui->lcdNumber->setMode(QLCDNumber::Dec);
    //设置显示方式
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);

    //新建一个QTimer对象
    timer = new QTimer();
    //设置定时器每个多少毫秒发送一个timeout()信号
    timer->setInterval(1000);
    //启动定时器
    timer->start();

    //信号和槽
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));



    //ui->sendButton->setShortcut(Qt::Key_Enter);//将字母区回车键与登录按钮绑定在一起


    udpSocket = new QUdpSocket(this);
    //创建一个类对象
    port = 8888;//端口号

    udpSocket ->bind(port,QUdpSocket::ShareAddress |QUdpSocket::ReuseAddressHint);
    //连接本机的端口

    connect (udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
    //readyRead 信号是有新的数据传入时就触发
    sendMessage(NewParticipant);

}

Widget::~Widget()
{
    delete ui;
}


//使用UDP来广播消息

void Widget::sendMessage(MessageType type, QString serverAddress)
{
    QByteArray data;
    //字节数组
    QDataStream out(&data,QIODevice::WriteOnly);
    //讲序列化的二进制数据传入到IO设备
    QString localHostName =QHostInfo::localHostName();
    //主机名字
    QString address =getIP();
    out<<type<<getUserName()<<localHostName;

    if(type==Message)
    {
        if(ui->messageTextEdit->toPlainText()=="")
        {
            QMessageBox::warning(this,tr("warning"),tr("Can not be empty"));
            return;
        }
        out<<address<<getMessage();
        ui->messageBrowser->verticalScrollBar()
                ->setValue(ui->messageBrowser->verticalScrollBar()->maximum());
        //设置滑动条
    }
    else if (type==NewParticipant)
        out<<address;
    else if (type==ParticipantLeft)
    {

    }


    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast,port);

    //把所有的数据都发送
}


//接受UDP信息


void Widget::processPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        //pendingDatagramSize为返回第一个在等待读取报文的size，resize函数是把datagram的size归一化到参数size的大小一样

        udpSocket->readDatagram(datagram.data(),datagram.size());
        QDataStream in(&datagram,QIODevice::ReadOnly);

        int messageType;

        in>>messageType;
        QString userName,localHostName,ipAddress,message;
        QString time = QDateTime::currentDateTime()
                .toString("yyyy-MM-dd hh:mm:ss");//将当前的时间转化到括号中的形式

        switch (messageType)
        {
            case Message:
                in >> userName >> localHostName >> ipAddress >> message;


                //用于区分主机，本来想给每个IP一个颜色的，想想反正只有两个用户，特判自己好了 哈哈
                if(localHostName .toStdString()=="Ginray"||ipAddress.toInt()%2==0)
                    ui->messageBrowser->setTextColor("#00BFFF");//设置文本颜色
                else
                    ui->messageBrowser->setTextColor("#b15bff");

                ui->messageBrowser->setCurrentFont(QFont("Times New Roman",15));//设置字体大小
                ui->messageBrowser->append(localHostName+": ");//消息输出


                ui->messageBrowser->setTextColor(Qt::gray);//设置文本颜色
                ui->messageBrowser->setCurrentFont(QFont("Times New Roman",10));//设置字体大小
                //ui->messageBrowser->append(time);

                ui->messageBrowser->insertPlainText("\t"+time);  //该函数能够实现不换行的输出
                ui->messageBrowser->moveCursor(QTextCursor::End);


                ui->messageBrowser->append(message);

                break;


        case NewParticipant:
            in >>userName >>localHostName >>ipAddress;
            newParticipant(userName,localHostName,ipAddress);
            break;

        case ParticipantLeft:
            in >>userName >>localHostName;
            participantLeft(userName,localHostName,time);
            break;
        }
    }
}


//新的IP加入局域网

void Widget::newParticipant(QString userName, QString localHostName, QString ipAddress)
{
    bool isEmpty =ui->userTableWidget->findItems(localHostName,Qt::MatchExactly).isEmpty();

    if(isEmpty)//没有找到一样的主机
    {
        QTableWidgetItem *user = new QTableWidgetItem(userName);
        QTableWidgetItem *host = new QTableWidgetItem(localHostName);
        QTableWidgetItem *ip = new QTableWidgetItem(ipAddress);

        ui->userTableWidget->insertRow(0);//先设置的是第0行，即新来的用户放在最上面
        ui->userTableWidget->setItem(0,0,host);//第0行的第1列...
       // ui->userTableWidget->setItem(0,1,user);
        ui->userTableWidget->setItem(0,1,ip);
        ui->messageBrowser->setTextColor(Qt::gray);
        ui->messageBrowser->setCurrentFont(QFont("Times New Roman",10));
        //arg为返回后面文本的一个副本,%1表示输出的内容按照第1个.arg后面的输出？
        ui->messageBrowser->append(tr("%1 online!").arg(localHostName));

        sendMessage(NewParticipant);//该句的功能是让新来的用户也能收到其它在线用户的信息，可拥于更新自己的好友列表
    }
}



// 处理用户离开
void Widget::participantLeft(QString userName, QString localHostName, QString time)
{
    //找到第一个对应的主机名
    int rowNum = ui->userTableWidget->findItems(localHostName, Qt::MatchExactly).first()->row();
    ui->userTableWidget->removeRow(rowNum);    //此句执行完后，rowCount()内容会自动减1
    ui->messageBrowser->setTextColor(Qt::gray);//设置文本颜色为灰色
    ui->messageBrowser->setCurrentFont(QFont("Times New Roman", 10));
    ui->messageBrowser->append(tr("%1 at %2 leave!").arg(userName).arg(time));

}




// 获取ip地址，获取本机ipv4
QString Widget::getIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();//此处的所有地址是指ipv4和ipv6的地址
    //foreach (variable, container),此处为按照容器list中条目的顺序进行迭代
    foreach (QHostAddress address, list) {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
            return address.toString();
    }
    return 0;
}



// 获得用户名
QString Widget::getUserName()
{
    QString userName =QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    userName = userName.section("/", -1, -1);
    return userName;
}


// 获得要发送的消息
QString Widget::getMessage()
{
    QString msg = ui->messageTextEdit->toHtml();//转化成html语言进行发送
    ui->messageTextEdit->setFocus();//重新设置光标输入焦点，即焦点保持不变
    ui->messageTextEdit->clear();//发送完后清空输入框
    return msg;
}


// 发送消息
void Widget::on_sendButton_clicked()
{
    sendMessage(Message);
}


//清空消息框
void Widget::on_clearButton_clicked()
{
    ui->messageTextEdit->clear();
    ui->messageTextEdit->setFocus();//重新设置光标输入焦点
}

//改变字体
void Widget::on_fontComboBox_currentFontChanged(QFont f)
{
    ui->messageTextEdit->setCurrentFont(f);
    ui->messageTextEdit->setFocus();
}



//改变字体大小

void Widget::on_sizeComboBox_currentIndexChanged(QString size)
{
   ui->messageTextEdit->setFontPointSize(size.toDouble());
   ui->messageTextEdit->setFocus();
}

//改变颜色

void Widget::on_colorToolBtn_clicked()
{
    color=QColorDialog::getColor(color,this);
    if(color.isValid())
    {
        ui->messageTextEdit->setTextColor(color);
        ui->messageTextEdit->setFocus();
    }
}

void Widget::onTimerOut()
{
  //获取系统当前时间
  QTime time = QTime::currentTime();
  //设置晶体管控件QLCDNumber上显示的内容
  ui->lcdNumber->display(time.toString("hh:mm:ss"));

}
