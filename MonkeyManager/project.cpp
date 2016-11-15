#include "project.h"

Project::Project(){
    m_name = "New Project";
    m_description = "Add description";
    m_created_date = QDate().currentDate();
    m_current_ticket = 0;
}

Project::Project(string name, string description){
    m_name = name;
    m_description = description;
    m_created_date = QDate().currentDate();
    m_current_ticket = 0;
}

Project::~Project(){
}

// task management functions
Task Project::find_task_by_name(string name){
    bool found = false;
    Task task = Task();
    for (m_tasks_iterator = m_tasks.begin(); m_tasks_iterator != m_tasks.end(); m_tasks_iterator++){
        if ((*m_tasks_iterator).get_name() == name){
            found = true;
            task = *m_tasks_iterator;
            break;
        }
    }
    if (!found) {
        throw ERR_TASK_NOT_FOUND;
    }
    return task;
}

void Project::remove_task(int index){
    m_tasks_iterator = m_tasks.begin() + index;
    m_tasks.erase(m_tasks_iterator);
}

void Project::add_task(Task new_task){
    m_tasks.push_back(new_task);
}

int Project::assign_ticket(){
    return m_current_ticket++;
}

// setter functions
void Project::set_created_date(QDate created_date){
    m_created_date = created_date;
}

void Project::set_name(string name){
    m_name = name;
}

void Project::set_description(string description){
    m_description = description;
}

void Project::set_tasks(vector<Task> tasks){
    m_tasks = tasks;
}
void Project::set_current_ticket(int ticket_number)
{
    m_current_ticket=ticket_number;
}

// getter functions
QDate Project::get_created_date(){
    return m_created_date;
}

string Project::get_name() const {
    return m_name;
}

string Project::get_description(){
    return m_description;
}

vector<Task> Project::get_tasks(){
    return m_tasks;
}

int Project::get_current_ticket()
{
    return m_current_ticket;
}
