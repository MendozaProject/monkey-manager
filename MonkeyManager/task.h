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
        Task();
        Task(int task_number);
        ~Task();

        void set_name(string name);
        void set_due_date(QDate due_date);
        void set_created_date(QDate created_date);
        void set_description(string description);
        void set_status(string status);

        string get_name();
        QDate get_due_date();
        QDate get_created_date();
        string get_description();
        long get_id_number();
        string get_status();
};



#endif
