#include "task.h"
//#include <time.h>

/**
 * @brief class constructor to initalize due date and created date
 */
Task::Task()
{
    m_due_date = QDate().currentDate();
    m_created_date = QDate().currentDate();
}

/**
 * @brief class constructor to initalize all variables to default
 * @param task_number id of task
 */
Task::Task(int task_number)
{
    m_name = "New Task";
    m_description = "Type description here";
    m_due_date = QDate().currentDate();
    m_created_date = QDate().currentDate();
    m_task_number = task_number;
    //m_id.set_current_datetime();
}

/**
 * @brief empty class destructor
 */
Task::~Task()
{
}

/**
 * @brief set name to user defined name
 * @param name Name of task
 */
void Task::set_name(string name)
{
    m_name = name;
}

/**
 * @brief set due date to user defined date
 * @param due_date Due date of task
 */
void Task::set_due_date(QDate due_date)
{
    m_due_date = due_date;
}

/*
 Set as the date from when it is created.
   NO USER INPUT
 */
/**
 * @brief set the created date to current time
 * @param created_date When task was created
 */
void Task::set_created_date(QDate created_date)
{
    m_created_date = created_date;
}

/**
 * @brief user set description of task
 * @param description define task
 */
void Task::set_description(string description)
{
    m_description = description;
}

/**
 * @brief user set status of task
 * @param status columb status of task
 */
void Task::set_status(string status)
{
    m_status = status;
}

/**
 * @brief user set id for the task
 * @param id ID number of task
 */
void Task::set_id_number(long id)
{
    m_id=id;
}

/**
 * @brief user set task number for task
 * @param task_number handle for task
 */
void Task::set_task_number(int task_number)
{
   m_task_number=task_number;
}

/**
 * @brief Gets the current name of the task
 * @return gets current name of task
 */
string Task::get_name()
{
    return m_name;
}

/**
 * @brief Gets the current due date of task
 * @return gets due date of task
 */
QDate Task::get_due_date()
{
    return m_due_date;
}

/**
 * @brief Gets the date of task creation
 * @return gets the created date of task
 */
QDate Task::get_created_date()
{
    return m_created_date;
}

/**
 * @brief Gets the current description of task
 * @return gets description of task
 */
string Task::get_description()
{
    return m_description;
}

/**
 * @brief gets the created id of task
 * @return gets id of task
 */
long Task::get_id_number()
{
    return m_id;
}

/**
 * @brief Gets the current status of task
 * @return gets status of task
 */
string Task::get_status()
{
    return m_status;
}

/**
 * @brief gets the set number of the task
 * @return gets number of task
 */
int Task::get_task_number()
{
    return m_task_number;
}

