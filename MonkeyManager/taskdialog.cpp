#include "taskdialog.h"
#include "ui_taskdialog.h"
#include "projectutils.h"

TaskDialog::TaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskDialog)
{
    ui->setupUi(this);
    m_task = ProjectUtils::Instance()->get_open_task();

    (ui->nameLineEdit)->setText(QString::fromUtf8(m_task.get_name().c_str()));
    (ui->descriptionTextEdit)->setText(QString::fromUtf8(m_task.get_description().c_str()));
    (ui->dateEdit)->setDate(m_task.get_due_date());

}

TaskDialog::~TaskDialog()
{
    delete ui;
}

void TaskDialog::on_buttonBox_accepted()
{
    //name, due date, description, status
    m_task.set_name(ui->nameLineEdit->text().toStdString());
    m_task.set_description(ui->descriptionTextEdit->toPlainText().toStdString());
    m_task.set_due_date(ui->dateEdit->date());
    m_task.set_status(ui->comboBox->currentText().toStdString());

    ProjectUtils::Instance()->get_open_project().add_task(m_task);
}

