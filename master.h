#ifndef MASTER_H
#define MASTER_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class master;
}

class master : public QDialog
{
    Q_OBJECT

public:
    explicit master(QWidget *parent = nullptr);
    ~master();

private slots:
//    void on_pushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::master *ui;
     QStandardItemModel *model;
};

#endif // MASTER_H
