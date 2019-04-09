#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <variables.h>
#include <QTextStream>
#include <QDebug>
#include <fstream>
#include <vector>
#include <string>
#include <locale.h>
#include <QTextCodec>
#include "master.h"



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

bool check_login(QString login)
{
    bool check = true;

    for (int i = 0; i < login.length(); i++)
    {
        if (login[i] > 64 && login[i] < 91)
        {
            continue;
        }
        if(login[i] > 96 && login[i] < 123)
        {
            continue;
        }
        if (login[i]==' ') login[i]='_';
        check = false;
    }

    return check;
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

std::string GetHas(std::string word)
  {
    if ((word.size() > 16) || (word.size() < 8))
    {
        return "@error@";
    }
    else
    {
        std::string Hash;
        std::string Salt = "safe";
        int Size = 16;
        int i;
        QVector<int> arr;
        int num[20] = { 13,23,54,756,2,34,12,87,87,456,34,23,76,89,23,54,23,54,65,32 };
        for ( i = 0; i < Size; i++)
        {
            if (i == int(word.size()))
            {
                Size = Size - i;
                i = 0;
            }

            arr.push_back((int)word[i] * num[i] * (Size - i) * word.length());
        }
        for (int i = 0; i < Salt.length(); i++)
            arr.push_back((int)Salt[i] * num[i] * (Salt.length() - i) * word.length());
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] % 7 == 0)
                Hash.push_back((arr[i] / 7) % 10 + 48);
            else
                Hash.push_back((arr[i]) % 26 + 65);
        }
        return Hash;
    }
}

void MainWindow::on_pushButton_2_clicked()//регистрация
{
   // QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1251"));
     QString loginreg=ui->login->text();
     QString pasreg=ui->pas->text();
 lreg=loginreg;
 preg=pasreg;
 QString text;
 std::ofstream fout;
 std::ifstream fin;
    if (check_login(lreg) == true)
    {
        fin.open("data.txt", std::ios::app);
       std::vector<std::string> logins_basa;
            while(!fin.eof())//считывание с файла логинов
        {

               std:: string mystr;
                fin>>mystr;
               logins_basa.push_back(mystr);
        }
         fin.close();
            bool match = false; //отвечает за наличие совпадений
                for(int i = 0 ; i < logins_basa.size();i++)
                {
                   if(loginreg.toLocal8Bit().constData() == logins_basa[i])
                    {
                       match = true;
                       ui->label_6->setText("такой логин существует");

                    }
                }

if (match==false)//если логин подходит
{
    if (check_password(preg) == true)
         {
            fout.open("data.txt", std::ios::app);
            fout<<loginreg.toLocal8Bit().constData();
            fout<<"\r\n";
            fout<<GetHas(pasreg.toLocal8Bit().constData());
            fout<<"\r\n";
            fout.close();
          
             ui->statusBar->showMessage("Cпасибо за регистрацию!");
             QMessageBox::information(this, "регистрация","Спасибо за регистрацию");

         }
         if (check_password(preg) == false)
         {
              ui->statusBar->showMessage("ошибка");
              ui->label_4->setText("пароль должен содержать не менее 1 цифры, 1 маленькой и заглавной буквы, должен быть длиннее 8 символов и короче 16(включительно)");
            pasreg.clear();
            ui->pas->clear();


         }
     }
    else
        {
             ui->statusBar->showMessage("//");
        }
    }

    }
    


void MainWindow::on_pushButton_clicked()//вход
{
    QString login=ui->login->text();
     QString pas=ui->pas->text();
     if(login=="K4{5NhrpEp" && pas=="%eN1c49#7r$%E405")
     {
        master window;
         window.setModal(true);
         window.exec();
     }
    std::ifstream fin;
    fin.open("data.txt", std::ios::app);
    std::vector<std::string> vhod;
    std::string vhod_l;
    std:: string vhod_p;
    QString test;
    bool l=0;
    bool p=0;
    QMessageBox::information(this, "регистрация","vhod");
        while(!fin.eof())//считывание с файла логинов
     {

           fin>>vhod_l;
           if (login.toLocal8Bit().constData()==vhod_l)
           {
               QMessageBox::information(this, "регистрация","ya v iiif");

               l=1;
           }


           fin>>vhod_p;
           if (GetHas(pas.toLocal8Bit().constData())==vhod_p) p=1;


           if (l==1 && p==1) break;
           else
           {
               l=0;
               p=0;
           }

    }

      fin.close();
      //login==lreg &&  pas==preg.toLocal8Bit().constData()
    if (l==1 && p==1){
        ui->statusBar->showMessage("вход");
        QMessageBox::information(this, "вход","Данные введены правильно");}
    else {
            ui->statusBar->showMessage("ошибка");
            QMessageBox::warning(this,"вход","допущена ошибка, возможно Вы еще не зарегестрированны");
    }
}



