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
        int m_selected_ticket;
    
    public:
        // constructors and destructors
        Project();
        Project(string name, string description);
        ~Project();
        
        // task management functions
        /**
         * @brief find_task_by_name - finds a task in the vector by name
         * @param name
         * @return Task vector iterator
         */
        vector<Task>::iterator find_task_by_name(string name);
        /**
         * @brief remove_task - removes a task in the task vector by index
         * @param index
         */
        void remove_task(vector<Task>::iterator index);
        /**
         * @brief add_task - add a new task to the vector
         * @param new_task
         */
        void add_task(Task new_task);
        /**
         * @brief assign_ticket - assigns a new ticket number to a task
         * @return int
         */
        int assign_ticket();
        /**
         * @brief editTask - set a tasks properties via the task passed in
         */
        void editTask(string, Task);
        
        // setter functions
        /**
         * @brief set_created_date - set the date created for a task
         * @param created_date
         */
        void set_created_date(QDate created_date);
        /**
         * @brief set_name - set the name of a task
         * @param name
         */
        void set_name(string name);
        /**
         * @brief set_description - set the description of a task
         * @param description
         */
        void set_description(string description);
        /**
         * @brief set_tasks - sets the project tasks to the ones passed in
         * @param tasks
         */
        void set_tasks(vector<Task> tasks);
        /**
         * @brief set_current_ticket - assigns current ticket number
         * @param ticket_number
         */
        void set_current_ticket(int ticket_number);
        /**
         * @brief set_selected_ticket - sets the selected ticket number
         */
        void set_selected_ticket(int);
        
        // getter functions
        /**
         * @brief get_created_date - get created date of a task
         * @return
         */
        QDate get_created_date();
        /**
         * @brief get_name - get a name of a task
         * @return QDate
         */
        string get_name() const;
        /**
         * @brief get_description - get a description of the task
         * @return string
         */
        string get_description();
        /**
         * @brief get_tasks - get tasks for a current project
         * @return string
         */
        vector<Task> get_tasks();
        /**
         * @brief get_current_ticket - get current ticket for a project
         * @return string
         */
        int get_current_ticket();
};

#endif
