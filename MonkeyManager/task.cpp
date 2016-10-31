#include "task.h"
//#include <time.h>

Task::Task(){
    m_name = "New Name";
    m_due_date = Date();
    m_created_date.set_current_datetime();
}

Task::Task(int task_number)
{
    m_name = "New Task";
    m_description = "Type description here";
    m_due_date.set_current_datetime();
    m_created_date.set_current_datetime();
    m_task_number = task_number;
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
void Task::set_created_date(Date created_date)
{
    m_created_date = created_date;
}

void Task::set_description(string description)
{
    m_description = description;
}

/*
 Creates a unique id for each task.
 Based it off of the millisecond at the time of creation.
    NO USER INPUT
 */
void Task::set_id(int id)
{
    //id = time;
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
