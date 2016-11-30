#include "taskwidget.h"

TaskWidget::TaskWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskWidget)
{
    ui->setupUi(this);
    name = ui->name;
    date = ui->date;

    temp_task = ProjectUtils::instance()->get_open_task();
    name->setText(QString::fromStdString(temp_task.get_name()));
    date->setText(temp_task.get_due_date().toString("MM/dd/yyyy"));
    widget_task_number =ProjectUtils::instance()->get_open_project().get_current_ticket();

}

TaskWidget::~TaskWidget()
{
    delete ui;
}
/*
*@brif Displays the open task as a detailed view.
*
*@Param QMouseEven * event: Mouse click
*/
void TaskWidget::mousePressEvent(QMouseEvent * event)
{
    MainWindow::getInstance()->DisplayDetailedView(temp_task);
    ProjectUtils::instance()->open_task(temp_task);
    ProjectUtils::instance()->get_open_project().set_selected_ticket( temp_task.get_task_number() );
}
