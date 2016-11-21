#include "mainwindow.h"
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

    temp_task = ProjectUtils::Instance()->get_open_task();
    name->setText(QString::fromStdString(temp_task.get_name()));
    date->setText(temp_task.get_due_date().toString("MM/dd/yyyy"));
    widget_task_number =ProjectUtils::Instance()->get_open_project().get_current_ticket();
    qDebug() << "From TaskWidget Creation: " + QString::fromStdString(temp_task.get_name()) ;

}

TaskWidget::~TaskWidget()
{
    delete ui;
}

void TaskWidget::mouseDoubleClickEvent(QMouseEvent * event)
{
   MainWindow::getInstance()->DisplayDetailedView(temp_task);
   //ProjectUtils::Instance()->open_task(temp_task);
   ProjectUtils::Instance()->get_open_project().set_selected_ticket( temp_task.get_task_number() );
}
