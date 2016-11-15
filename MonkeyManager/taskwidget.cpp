#include "taskwidget.h"
#include "task.h"
#include "ui_taskwidget.h"
#include "project.h"
#include "projectutils.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QLabel>

TaskWidget::TaskWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskWidget)
{
    ui->setupUi(this);
    name = ui->name;
    date = ui->date;

    Task temp_task = ProjectUtils::Instance()->get_open_task();
    name->setText(QString::fromStdString(temp_task.get_name()));
    date->setText(temp_task.get_due_date().toString("yyyy.MM.dd"));

    qDebug() << "From TaskWidget Creation: " + QString::fromStdString(temp_task.get_name()) ;

}

TaskWidget::~TaskWidget()
{
    delete ui;
}
