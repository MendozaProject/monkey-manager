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
    widget_task_number=ProjectUtils::Instance()->get_open_project().get_current_ticket();
    qDebug() << "From TaskWidget Creation: " + QString::fromStdString(temp_task.get_name()) ;

}

TaskWidget::~TaskWidget()
{
    delete ui;
}
void TaskWidget::mousePressEvent(QMouseEvent * event)
{
   //qDebug() << "hey";
   qDebug() << QString::fromStdString(to_string(widget_task_number));
   //QString name2= name->text();
    //int task_number = ui->date;
   //qDebug() << name2;


}
