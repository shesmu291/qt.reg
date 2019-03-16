#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
   //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1251"));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
