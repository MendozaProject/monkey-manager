#ifndef TASK_H
#define TASK_H
#pragma once

//#include <string>

#include "date.h"

using namespace std;

class Task {
    private:
        string m_name;
        Date m_due_date;
        Date m_created_date;
        string m_description;
        int   m_id;
        int    m_status;
        int m_task_number;

    public slots:
        Task();
        Task(string name, int task_number, Date due_date);
        ~Task();

        void set_name(string name);
        void set_due_date(Date due_date);
        void set_created_date();
        void set_description(string description);
        void set_id();
        void set_status(int status);

        string get_name();
        Date get_due_date();
        Date get_created_date();
        string get_description();
        long get_id_number();
        int get_status();
};



#endif
