#include "master.h"
#include "ui_master.h"

master::master(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::master)
{
    ui->setupUi(this);
    model=new QStandardItemModel(5,2,this);
    //ui->tableWid
}

master::~master()
{
    delete ui;
}
