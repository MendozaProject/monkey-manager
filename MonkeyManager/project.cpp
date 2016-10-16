#include "project.h"

Project::Project(){

}

Project::Project(string name, string description){
    m_name = name;
    m_description = description;
    Date date = Date();
    date.set_current_datetime();
    m_created_date = date;
}

Project::~Project(){

}

// task management functions
Task Project::find_task_by_name(string name){
    bool found = false;
    Task task;
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

// setter functions
void Project::set_created_date(Date created_date){
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

// getter functions
Date Project::get_created_date(){
    return m_created_date;
}

string Project::get_name(){
    return m_name;
}

string Project::get_description(){
    return m_description;
}

vector<Task> Project::get_tasks(){
    return m_tasks;
}

