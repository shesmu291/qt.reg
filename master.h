#ifndef MASTER_H
#define MASTER_H

#include <QDialog>

namespace Ui {
class master;
}

class master : public QDialog
{
    Q_OBJECT

public:
    explicit master(QWidget *parent = nullptr);
    ~master();

private:
    Ui::master *ui;
};

#endif // MASTER_H
