#include "task.h"
//#include <time.h>

Task::Task()
{
    m_due_date = QDate().currentDate();
    m_created_date = QDate().currentDate();
}

Task::Task(int task_number)
{
    m_name = "New Task";
    m_description = "Type description here";
    m_due_date = QDate().currentDate();
    m_created_date = QDate().currentDate();
    m_task_number = task_number;
    //m_id.set_current_datetime();
}

Task::~Task()
{
}

void Task::set_name(string name)
{
    m_name = name;
}

void Task::set_due_date(QDate due_date)
{
    m_due_date = due_date;
}

/*
 Set as the date from when it is created.
   NO USER INPUT
 */
void Task::set_created_date(QDate created_date)
{
    m_created_date = created_date;
}

void Task::set_description(string description)
{
    m_description = description;
}

void Task::set_status(string status)
{
    m_status = status;
}
void Task::set_id_number(long id)
{
    m_id=id;
}

void Task::set_task_number(int task_number)
{
   m_task_number=task_number;
}

string Task::get_name()
{
    return m_name;
}

QDate Task::get_due_date()
{
    return m_due_date;
}

QDate Task::get_created_date()
{
    return m_created_date;
}

string Task::get_description()
{
    return m_description;
}

long Task::get_id_number()
{
    return m_id;
}

string Task::get_status()
{
    return m_status;
}
int Task::get_task_number()
{
    return m_task_number;
}

