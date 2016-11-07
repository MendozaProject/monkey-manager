#ifndef PROJECT_H
#define PROJECT_H
#pragma once

#include <string>
#include <vector>
#include <iterator>

#include "constants.h"
#include "task.h"

using namespace std;

class Project {
    private:
        QDate m_created_date;
        string m_name;
        string m_description;
        vector<Task> m_tasks;
        vector<Task>::iterator m_tasks_iterator;
        int m_current_ticket;
    
    public:
        // constructors and destructors
        Project();
        Project(string name, string description);
        ~Project();
        
        // task management functions
        Task find_task_by_name(string name);
        void remove_task(int index);
        void add_task(Task new_task);
        int assign_ticket();
        
        // setter functions
        void set_created_date(QDate created_date);
        void set_name(string name);
        void set_description(string description);
        void set_tasks(vector<Task> tasks);
        void set_current_ticket(int ticket_number);
        
        // getter functions
        QDate get_created_date();
        string get_name();
        string get_description();
        vector<Task> get_tasks();
        int get_current_ticket();
};

#endif
