/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextEdit *messageTextEdit;
    QTextBrowser *messageBrowser;
    QTableWidget *userTableWidget;
    QPushButton *sendButton;
    QTextEdit *textEdit;
    QPushButton *clearButton;
    QFontComboBox *fontComboBox;
    QComboBox *sizeComboBox;
    QPushButton *colorToolBtn;
    QLCDNumber *lcdNumber;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 450);
        Widget->setMaximumSize(QSize(800, 450));
        Widget->setAutoFillBackground(true);
        messageTextEdit = new QTextEdit(Widget);
        messageTextEdit->setObjectName(QStringLiteral("messageTextEdit"));
        messageTextEdit->setEnabled(true);
        messageTextEdit->setGeometry(QRect(270, 270, 501, 121));
        messageTextEdit->setAutoFillBackground(false);
        messageTextEdit->setStyleSheet(QStringLiteral(""));
        messageBrowser = new QTextBrowser(Widget);
        messageBrowser->setObjectName(QStringLiteral("messageBrowser"));
        messageBrowser->setGeometry(QRect(270, 10, 501, 221));
        messageBrowser->setStyleSheet(QStringLiteral(""));
        userTableWidget = new QTableWidget(Widget);
        if (userTableWidget->columnCount() < 2)
            userTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        userTableWidget->setObjectName(QStringLiteral("userTableWidget"));
        userTableWidget->setGeometry(QRect(30, 10, 201, 381));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(userTableWidget->sizePolicy().hasHeightForWidth());
        userTableWidget->setSizePolicy(sizePolicy);
        userTableWidget->setMinimumSize(QSize(0, 0));
        userTableWidget->setBaseSize(QSize(0, 0));
        QFont font;
        font.setKerning(true);
        userTableWidget->setFont(font);
        userTableWidget->setAutoFillBackground(true);
        userTableWidget->setStyleSheet(QStringLiteral(""));
        userTableWidget->setAutoScrollMargin(16);
        userTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        userTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        userTableWidget->setShowGrid(false);
        userTableWidget->horizontalHeader()->setDefaultSectionSize(80);
        sendButton = new QPushButton(Widget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(590, 400, 93, 28));
        sendButton->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\232\266\344\271\246\";"));
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 801, 451));
        textEdit->setAutoFillBackground(true);
        textEdit->setStyleSheet(QStringLiteral("border-image: url(:/new/0.jpg);"));
        clearButton = new QPushButton(Widget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(360, 400, 93, 28));
        clearButton->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\232\266\344\271\246\";"));
        fontComboBox = new QFontComboBox(Widget);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setGeometry(QRect(270, 240, 171, 22));
        sizeComboBox = new QComboBox(Widget);
        sizeComboBox->setObjectName(QStringLiteral("sizeComboBox"));
        sizeComboBox->setEnabled(true);
        sizeComboBox->setGeometry(QRect(440, 240, 87, 22));
        sizeComboBox->setStyleSheet(QStringLiteral(""));
        colorToolBtn = new QPushButton(Widget);
        colorToolBtn->setObjectName(QStringLiteral("colorToolBtn"));
        colorToolBtn->setGeometry(QRect(550, 240, 90, 24));
        colorToolBtn->setStyleSheet(QStringLiteral(""));
        colorToolBtn->setFlat(false);
        lcdNumber = new QLCDNumber(Widget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(660, 240, 111, 23));
        textEdit->raise();
        messageTextEdit->raise();
        messageBrowser->raise();
        userTableWidget->raise();
        sendButton->raise();
        clearButton->raise();
        fontComboBox->raise();
        sizeComboBox->raise();
        colorToolBtn->raise();
        lcdNumber->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\345\261\200\345\237\237\347\275\221\350\201\212\345\244\251@Ginray", 0));
        QTableWidgetItem *___qtablewidgetitem = userTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "\344\270\273\346\234\272\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem1 = userTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "IP\345\234\260\345\235\200", 0));
        sendButton->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", 0));
        clearButton->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", 0));
        sizeComboBox->clear();
        sizeComboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "12", 0)
         << QApplication::translate("Widget", "13", 0)
         << QApplication::translate("Widget", "14", 0)
         << QApplication::translate("Widget", "15", 0)
         << QApplication::translate("Widget", "16", 0)
         << QApplication::translate("Widget", "17", 0)
         << QApplication::translate("Widget", "18", 0)
         << QApplication::translate("Widget", "19", 0)
         << QApplication::translate("Widget", "20", 0)
         << QApplication::translate("Widget", "21", 0)
         << QApplication::translate("Widget", "22", 0)
         << QApplication::translate("Widget", "23", 0)
         << QApplication::translate("Widget", "24", 0)
         << QApplication::translate("Widget", "25", 0)
         << QApplication::translate("Widget", "26", 0)
         << QApplication::translate("Widget", "27", 0)
         << QApplication::translate("Widget", "28", 0)
         << QApplication::translate("Widget", "29", 0)
         << QApplication::translate("Widget", "30", 0)
         << QString()
        );
        colorToolBtn->setText(QApplication::translate("Widget", "\351\242\234\350\211\262", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
