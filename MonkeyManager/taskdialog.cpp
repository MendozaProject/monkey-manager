#include "taskdialog.h"
#include "task.h"
#include "ui_taskdialog.h"

taskdialog::taskdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::taskdialog)
{
    ui->setupUi(this);
}

taskdialog::~taskdialog()
{
    delete ui;
}
