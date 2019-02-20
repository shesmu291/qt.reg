#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <variables.h>
#include <QTextStream>
#include <QDebug>
#include <fstream>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
bool check_password(QString password)
{
    int quantity_numbers = 0;
    int big_registr = 0, small_registr = 0;
    bool check = true;
    for (int i = 0; i < password.length(); i++)
    {
        if (password[i] == '1' || password[i] == '2' || password[i] == '3')
        {
            quantity_numbers++;
        }
        if (password[i] == '4' || password[i] == '5' || password[i] == '6')
        {
            quantity_numbers++;
        }
        if (password[i] == '7' || password[i] == '8' || password[i] == '9')
        {
            quantity_numbers++;
        }
        if (password[i] == '0')
        {
            quantity_numbers++;
        }
    }
    for (int i = 0; i < password.length(); i++)
    {
        if (password[i] > 64 && password[i] < 91)
        {
            big_registr++;
        }
        if (password[i] > 96 && password[i] < 123)
        {
            small_registr++;
        }
    }
    if (quantity_numbers == 0)
    {
        check = false;
    }
    if (small_registr == 0 || big_registr == 0)
    {
        check = false;
    }
    if (password.length() < 8)
    {
        check = false;
    }
    if (password.length() > 16)
    {
        check = false;
    }
    return check;
}

void MainWindow::on_pushButton_2_clicked()
{
    //QFile data("data1.txt");


   /* if (!data.open(QIODevice::WriteOnly))
    {
        qDebug() << "Ошибка при открытии файла";
    }*/
     QString loginreg=ui->login->text();
     QString pasreg=ui->pas->text();
 lreg=loginreg;
 preg=pasreg;
 QString text;
 std::ofstream fout;
 //fout.open("database.txt", std::ios::app);

     while (true)
     {
         if (check_password(preg) == true)
         {


            // fout.open(QIODevice::Append );

             //QTextStream stream(&data);

            fout.open("database.txt", std::ios::app);
            fout<<loginreg.toLocal8Bit().constData();
            fout<<"\r\n";
            fout<<pasreg.toLocal8Bit().constData();
             fout<<"\r\n";
            //fout<<"\r\n"+loginreg;
            //fout<<"\r\n"+pasreg;

            // data.close();
             ui->statusBar->showMessage("Cпасибо за регистрацию!");
             QMessageBox::information(this, "регистрация","Спасибо за регистрацию");
             break;
         }
         if (check_password(preg) == false)
         {
              ui->statusBar->showMessage("ошибка");

            QMessageBox::warning(this,"регистрация","пароль должен содержать не менее 1 цифры, 1 маленькой и заглавной буквы, должен быть длиннее 8 символов и короче 16(включительно)");
            pasreg.clear();
            break;

         }
     }

}


void MainWindow::on_pushButton_clicked()
{
    QString login=ui->login->text();
     QString pas=ui->pas->text();

     if (login==lreg && pas==preg){
         ui->statusBar->showMessage("вход");
         QMessageBox::information(this, "вход","Данные введены правильно");}
     else {
             ui->statusBar->showMessage("ошибка");
             QMessageBox::warning(this,"вход","допущена ошибка, возможно Вы еще не зарегестрированны");
     }
}


