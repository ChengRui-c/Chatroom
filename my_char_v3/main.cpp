#include <QApplication>
#include "widget.h"
#include <QtWidgets>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();

    //进入事件循环

}
