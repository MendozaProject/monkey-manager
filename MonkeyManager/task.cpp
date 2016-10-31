#include "task.h"
//#include <time.h>

Task::Task()
{
    m_due_date = Date();
    m_created_date.set_current_datetime();
}

Task::Task(int task_number)
{
    m_name = "New Name";
    m_descripion = "Add description here.";
    m_due_date.set_current_datetime();
    m_created_date.set_current_datetime();
    m_task_number = task_number;
    m_id.set_current_datetime();
}

Task::~Task()
{
}

void Task::set_name(string name)
{
    m_name = name;
}

void Task::set_due_date(Date due_date)
{
    m_due_date = due_date;
}

/*
 Set as the date from when it is created.
   NO USER INPUT
 */
void Task::set_created_date(Date create)
{
    m_created_date = created_date;
}

void Task::set_description(string description)
{
    m_description = description;
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
    return m_due_date;
}

Date Task::get_created_date()
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

int Task::get_status()
{
    return m_status;
}
