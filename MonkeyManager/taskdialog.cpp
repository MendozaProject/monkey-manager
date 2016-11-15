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

    m_task = ProjectUtils::Instance()->get_open_task();


    taskDialogAccept = ui->buttonBox;
    MainWindow* m = MainWindow::getInstance();
    (ui->nameLineEdit)->setText(QString::fromUtf8(m_task.get_name().c_str()));
    (ui->descriptionTextEdit)->setText(QString::fromUtf8(m_task.get_description().c_str()));
    (ui->dateEdit)->setDate(m_task.get_due_date());
    connect(taskDialogAccept, SIGNAL(accepted()), m, SLOT(onTaskDialogAccepted()) );

}

TaskDialog::~TaskDialog()
{
    delete ui;
}

void TaskDialog::on_buttonBox_accepted()
{
    //int r=1;
    //name, due date, description, status
    m_task.set_name(ui->nameLineEdit->text().toStdString());
    m_task.set_description(ui->descriptionTextEdit->toPlainText().toStdString());
    m_task.set_due_date(ui->dateEdit->date());
    m_task.set_status(ui->comboBox->currentText().toStdString());

//    QString test = QString::fromStdString(m_task.get_name());
//    qDebug() << "!!!!!!!!!!!!!!!!!!!!!!" << test;

    ProjectUtils::Instance()->get_open_project().add_task(m_task);


    qDebug() << "CLICKED NEW TASK BUTTON";
}

Task TaskDialog::getTask(Task task)
{
    return task;
}
