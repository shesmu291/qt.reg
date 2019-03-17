#include "master.h"
#include "ui_master.h"

master::master(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::master)
{
    ui->setupUi(this);
}

master::~master()
{
    delete ui;
}
