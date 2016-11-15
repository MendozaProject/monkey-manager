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

//    name = new QLabel("name");
//    date = new QLabel("date");

//    ui->nameDate->addWidget(name);
//    ui->nameDate->addWidget(date);

     vector<Task> temp_tasks = ProjectUtils::Instance()->get_open_project().get_tasks();
    qDebug() << "!!!!!!!!!!!!!!!!!!!!!!" ;
     QString test = QString::fromStdString(temp_tasks[0].get_name());
     qDebug() << "!!!!!!!!!!!!!!!!!!!!!!" << test;


     if(temp_tasks.size() !=0) {
        Task task = temp_tasks[(temp_tasks.size()-1)];
        ui->name->setText(QString::fromStdString(task.get_name()));
        //ui->date->setText(task.get_due_date().toString());
     }
     else {
         Task task = temp_tasks[0];
         ui->name->setText(QString::fromStdString(task.get_name()));
         //ui->date->setText(task.get_due_date().toString());
      }
     }

TaskWidget::~TaskWidget()
{
    delete ui;
}
