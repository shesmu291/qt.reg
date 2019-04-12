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


void master::on_pushButton_clicked()
{
   /*std:: ifstream fin;

        fin.open("data.txt");

        std::string str;
        int ch = 0;
        bool es=0;
        QVector<QString> names;
        QString sl=ui->pos->text();
        QString qs;
        for(int i=0;i<fin.eof();i++)
        {
            fin >> str;
            if (ch==1)
            {
               qs = QString::fromLocal8Bit(str.c_str());
               names.push_back(qs);
               ch=0;
            }
            if (str == sl.toLocal8Bit().constData())
            {
               qs = QString::fromLocal8Bit(str.c_str());
               names.push_back(qs);
               ch=1;
               es=1;
            }


        }
        for (int i = 0; i < names.size(); i++)
        {
            ui->textEdit->insertPlainText(names[i]);

        }

       if(es==0)	 ui->textEdit->insertPlainText("Нет элементов, удоволетворяющих условиям поиска");
        fin.close();*/

}
