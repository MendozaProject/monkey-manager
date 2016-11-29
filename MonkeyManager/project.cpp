#include "project.h"

Project::Project(){
    m_name = "New Project";
    m_description = "Add description";
    m_created_date = QDate().currentDate();
    m_current_ticket = 0;
    m_selected_ticket = m_current_ticket;
}

Project::Project(string name, string description){
    m_name = name;
    m_description = description;
    m_created_date = QDate().currentDate();
    m_current_ticket = 0;
    m_selected_ticket = m_current_ticket;
}

Project::~Project(){
}

// task management functions
/**
 * @brief Project::find_task_by_name - finds a task in the vector by name
 * @param name
 * @return
 */
vector<Task>::iterator Project::find_task_by_name(string name) {
    bool found = false;
    for (m_tasks_iterator = m_tasks.begin(); m_tasks_iterator != m_tasks.end(); m_tasks_iterator++){
        if ((*m_tasks_iterator).get_name() == name){
            found = true;
            break;
        }
    }
    if (!found) {
        throw ERR_TASK_NOT_FOUND;
    }
    return m_tasks_iterator;
}

/**
 * @brief Project::remove_task - removes a task in the task vector by index
 * @param index
 */
void Project::remove_task(vector<Task>::iterator index) {
    for (m_tasks_iterator = m_tasks.begin(); m_tasks_iterator != index; m_tasks_iterator++){;}
    m_tasks.erase(m_tasks_iterator);
}

/**
 * @brief Project::add_task - add a new task to the vector
 * @param new_task
 */

void Project::add_task(Task new_task){
    new_task.set_task_number(assign_ticket());
    m_tasks.push_back(new_task);
}

/**
 * @brief Project::assign_ticket - assigns a new ticket number to a task
 * @return
 */

int Project::assign_ticket(){
    return m_current_ticket++;
}

/**
 * @brief Project::editTask - set a tasks properties via the task passed in
 * @param task_name
 * @param r_task
 */

void Project::editTask(string task_name, Task r_task)
{
    vector<Task>::iterator task = find_task_by_name(task_name);

    task->set_name( r_task.get_name() );
    task->set_due_date( r_task.get_due_date() );
    task->set_created_date( r_task.get_created_date() );
    task->set_description( r_task.get_description() );
    task->set_status( r_task.get_status() );
    task->set_id_number( r_task.get_id_number() );
}

// setter functions

/**
 * @brief Project::set_created_date - set the date created for a task
 * @param created_date
 */
void Project::set_created_date(QDate created_date){
    m_created_date = created_date;
}

/**
 * @brief Project::set_name - set the name of a task
 * @param name
 */

void Project::set_name(string name){
    m_name = name;
}

/**
 * @brief Project::set_description - set the description of a task
 * @param description
 */

void Project::set_description(string description){
    m_description = description;
}

/**
 * @brief Project::set_tasks - sets the project tasks to the ones passed in
 * @param tasks
 */

void Project::set_tasks(vector<Task> tasks){
    m_tasks = tasks;
}

/**
 * @brief Project::set_current_ticket - assigns current ticket number
 * @param ticket_number
 */

void Project::set_current_ticket(int ticket_number)
{
    m_current_ticket=ticket_number;
}

/**
 * @brief Project::set_selected_ticket - sets the selected ticket number
 * @param ticket_number
 */

void Project::set_selected_ticket(int ticket_number)
{
    m_selected_ticket = ticket_number;
}

// getter functions
/**
 * @brief Project::get_created_date - get created date of a task
 * @return
 */
QDate Project::get_created_date(){
    return m_created_date;
}

/**
 * @brief Project::get_name - get a name of a task
 * @return
 */

string Project::get_name() const {
    return m_name;
}

/**
 * @brief Project::get_description - get a description of the task
 * @return
 */

string Project::get_description(){
    return m_description;
}

/**
 * @brief Project::get_tasks - get tasks for a current project
 * @return
 */

vector<Task> Project::get_tasks(){
    return m_tasks;
}

/**
 * @brief Project::get_current_ticket - get current ticket for a project
 * @return
 */

int Project::get_current_ticket()
{
    return m_current_ticket;
}


