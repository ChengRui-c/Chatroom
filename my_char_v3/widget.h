#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QColorDialog>//用于更改颜色
class QLCDNumber;
class QTimer;
class QUdpSocket;

namespace Ui {
class Widget;
}

// 枚举变量标志信息的类型，分别为消息，新用户加入，用户退出，文件名，拒绝接受文件
enum MessageType{Message, NewParticipant, ParticipantLeft};


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void newParticipant(QString userName,
                        QString localHostName, QString ipAddress);
    void participantLeft(QString userName,
                         QString localHostName, QString time);
    void sendMessage(MessageType type, QString serverAddress="");


    QString getIP();
    QString getUserName();
    QString getMessage();
    void timeUpdate()  ;
    void chTime()  ;

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;
    qint16 port;
    QColor color;
    QLCDNumber *lcd;
    QTimer *timer;

private slots:
    void processPendingDatagrams();
    void onTimerOut();
    void on_sendButton_clicked();          // 自动连接命名规则 下同
    void on_clearButton_clicked();
    void on_fontComboBox_currentFontChanged(QFont f);
    void on_sizeComboBox_currentIndexChanged(QString size);
    void on_colorToolBtn_clicked();

};

#endif // WIDGET_H
