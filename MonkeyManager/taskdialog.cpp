#include "taskdialog.h"
#include "ui_taskdialog.h"
#include "projectutils.h"
#include "mainwindow.h"
#include <QDebug>
#include <iostream>

TaskDialog::TaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskDialog)
{
    ui->setupUi(this);

    if( MainWindow::getInstance()->getEditFlag() )
        m_task = ProjectUtils::instance()->get_open_task();
    else
        m_task = Task();

    taskDialogAccept = ui->buttonBox;
    (ui->nameLineEdit)->setText(QString::fromUtf8(m_task.get_name().c_str()));
    (ui->descriptionTextEdit)->setText(QString::fromUtf8(m_task.get_description().c_str()));
    (ui->dateEdit)->setDate(m_task.get_due_date());
}

TaskDialog::~TaskDialog()
{
    delete ui;
}

/*
*@brief Once the user presses "Ok" the following data will be taken as an input 
*	for each task: Name, Due Date, Description, and Status.
*/

void TaskDialog::on_buttonBox_accepted()
{
    //name, due date, description, status
    m_task.set_name(ui->nameLineEdit->text().toStdString());
    m_task.set_description(ui->descriptionTextEdit->toPlainText().toStdString());
    m_task.set_due_date(ui->dateEdit->date());
    m_task.set_status(ui->comboBox->currentText().toStdString());

    if( MainWindow::getInstance()->getEditFlag() && !(ProjectUtils::instance()->get_open_project().get_tasks().empty()) ) {
        ProjectUtils::instance()->get_open_project().editTask(ProjectUtils::instance()->get_open_task().get_name(), m_task);
        ProjectUtils::instance()->get_projects().at(ProjectUtils::instance()->get_current_project_index()).editTask(ProjectUtils::instance()->get_open_task().get_name(), m_task);
    }
    else {
        ProjectUtils::instance()->get_open_project().add_task(m_task);
        ProjectUtils::instance()->get_projects().at(ProjectUtils::instance()->get_current_project_index()).add_task(m_task);
    }

    ProjectUtils::instance()->open_task(m_task);

    MainWindow::getInstance()->onTaskDialogAccepted();
}

/*
*@brief Returns the task with all the inputed data
*
*@param Task current task 
*/
Task TaskDialog::getTask(Task task)
{
    return task;
}
