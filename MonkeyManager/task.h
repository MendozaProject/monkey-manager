#ifndef TASK_H
#define TASK_H
#pragma once

#include <string>
#include <QDate>

using namespace std;

class Task {
    private:
        string m_name;
        QDate   m_due_date;
        QDate   m_created_date;
        string m_description;
        int    m_id;
        string m_status;
        int    m_task_number;

    public:
       /**
        * @brief class constructor to initalize due date and created date
        */
        Task();
        /**
         * @brief class constructor to initalize all variables to default
         */
        Task(int task_number);
        /**
         * @brief empty class destructor
         */
        ~Task();

        /**
         * @brief set name to user defined name
         */
        void set_name(string name);

        /**
         * @brief set due date to user defined date
         */
        void set_due_date(QDate due_date);

        /**
         * @brief set the created date to current time
         */
        void set_created_date(QDate created_date);

        /**
         * @brief user set description of task
         */
        void set_description(string description);

        /**
         * @brief user set status of task
         */
        void set_status(string status);

        /**
         * @brief user set id for the task
         */
        void set_id_number(long id);

        /**
         * @brief user set task number for task
         */
        void set_task_number(int task_number);

        /**
         * @brief Gets the current name of the task
         */
        string get_name();

        /**
         * @brief Gets the current due date of task
         */
        QDate get_due_date();

        /**
         * @brief Gets the date of task creation
         */
        QDate get_created_date();

        /**
         * @brief Gets the current description of task
         */
        string get_description();

        /**
         * @brief gets the created id of task
         */
        long get_id_number();

        /**
         * @brief Gets the current status of task
         */
        string get_status();

        /**
         * @brief gets the set number of the task
         */
        int get_task_number();
};



#endif
