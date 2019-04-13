#include "master.h"
#include "ui_master.h"
#include <QPlainTextEdit>
#include <QFile>
#include <QWidget>
#include <fstream>

master::master(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::master)
{
    ui->setupUi(this);
    QFile file("data.txt");
    QStringList strList;
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        ui->textEdit->setReadOnly ( true );
        ui->textEdit->insertPlainText(file.readAll());
        file.close();
    }

}

master::~master()
{
    delete ui;

}


