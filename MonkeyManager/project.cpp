#include "project.h"

#include <QDebug>

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
vector<Task>::iterator Project::find_task_by_name(string name){
    bool found = false;
    //Task* task;// = Task();
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

void Project::remove_task(vector<Task>::iterator index) {
    //m_tasks_iterator = m_tasks.begin() + index;
    m_tasks.erase(index);
}

void Project::add_task(Task new_task){
    new_task.set_task_number(assign_ticket());
    m_tasks.push_back(new_task);
    qDebug() << "From Project add task: " + QString::fromStdString(to_string(m_tasks.size()));
}

int Project::assign_ticket(){
    return m_current_ticket++;
}

void Project::editTask(string task_name, Task r_task)
{
    vector<Task>::iterator task = find_task_by_name(task_name);
    //  ^^^ this is the kind of stuff we should be doing

    task->set_name( r_task.get_name() );
    task->set_due_date( r_task.get_due_date() );
    task->set_created_date( r_task.get_created_date() );
    task->set_description( r_task.get_description() );
    task->set_status( r_task.get_status() );
    task->set_id_number( r_task.get_id_number() );
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

void Project::set_selected_ticket(int ticket_number)
{
    m_selected_ticket = ticket_number;
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
    qDebug() << "From Project get tasks: " + QString::fromStdString(to_string(m_tasks.size()));
}

int Project::get_current_ticket()
{
    return m_current_ticket;
}

int Project::get_selected_ticket()
{
    return m_selected_ticket;
}

