#include "taskdialog.h"
#include "ui_taskdialog.h"

TaskDialog::TaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskDialog)
{
    ui->setupUi(this);
}

TaskDialog::~TaskDialog()
{
    delete ui;
}

void TaskDialog::on_buttonBox_accepted()
{
    //name, due date, description, status
    m_task.set_name(ui->lineEdit->text().toStdString());
    m_task.set_description(ui->textEdit_2->text().toStdString());
    m_task.set_due_date(ui->dateEdit);
    m_task.set_status(ui->comboBox->currentText());
}

