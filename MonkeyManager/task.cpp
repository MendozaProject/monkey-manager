#include "task.h"
#include "ui_task.h"

Task::Task(QWidget *parent){
    m_name = "New Name";
    m_due_date = Date();
    m_due_date.set_current_datetime();

    QTask(parent),
        ui(new Ui::Task)
        {
            ui->setupUi(this);
        }
}

Task::Task(string name)
{
    m_name = name;
    m_due_date = Date();
    m_due_dat.set_currnet_datetime();
}

Task::~Task()
{
    delete ui;
}

void Task::set_name(string name)
{
    m_name = name;
}

void Task::set_due_date(Date due_date)
{
    m_due_date = due_date;
}

void Task::set_description(string description)
{
    m_description = description;
}

void Task::set_id(string id)
{
    m_id = id;
}

void Task::set_status(int status)
{
    m_status = status;
}

string Task::get_name()
{
    return m_name;
}

Date Task::get_due_date()
{
    return m_created_date;
}

Date Task::get_created_date()
{
    return m_due_date;
}

string Task::get_description()
{
    return m_description;
}

long Task::get_id_number()
{
    return m_id;
}

int Task::get_status()
{
    return m_status;
}
