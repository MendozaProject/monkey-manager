#include "task.h"

Task::Task(){
    m_name = "New Name";
    m_due_date = Date();
    m_due_date.set_current_datetime();
}

Task::Task(string name){

}

Task::~Task(){

}

void Task::set_name(string name){

}

void Task::set_due_date(Date due_date){

}

void Task::set_description(string description){

}

void Task::set_id(string id){

}

void Task::set_status(int status){

}

string Task::get_name(){
    return m_name;
}

Date Task::get_due_date(){
    return m_created_date;
}

Date Task::get_created_date(){
    return m_due_date;
}

string Task::get_description(){
    return m_description;
}

long Task::get_id_number(){
    return m_id;
}

int Task::get_status(){
    return m_status;
}
