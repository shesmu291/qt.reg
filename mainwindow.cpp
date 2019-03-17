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
                       ui->label_6->setText("такой логин существует999");

                    }
                }

if (match==false)//если логин подходит
{

    //std::vector<std::string> parol_basa;
	
     /*   while(!fin.eof()) //нужно будет пофиксить считывание паролей
        {
            std::string par;
            fin>>par;
            parol_basa.push_back(par);
        }
    */
	//if(match == true) ошибка
	//else все гуд, регистрация
	//ниже не смотрел
       /* QString str;
            int ch = 0;
            std::vector<std::string> names;
            std::string sl = "login";
            while (!fin.eof())
            {
                fin >> str;

                names.push_back(str);
            }
            for (int i = 0; i < names.size(); i++)
            {
                if (names[i] == sl) ch++;
            }
            if(ch>0)
            {*/

         if (check_password(preg) == true)
         {

        fout.open("data.txt", std::ios::app);
            fout<<loginreg.toLocal8Bit().constData();
            fout<<"\r\n";
            fout<<pasreg.toLocal8Bit().constData();
             fout<<"\r\n";

             fout.close();
          
             ui->statusBar->showMessage("Cпасибо за регистрацию!");
             QMessageBox::information(this, "регистрация","Спасибо за регистрацию");

         }
         if (check_password(preg) == false)
         {
              ui->statusBar->showMessage("ошибка");

            QMessageBox::warning(this,"регистрация","пароль должен содержать не менее 1 цифры, 1 маленькой и заглавной буквы, должен быть длиннее 8 символов и короче 16(включительно)");
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



