#ifndef TASK_H
#define TASK_H

#include <string>

#include "task.cpp"
#include "date.h"

using namespace std;

class Task {
    private:
        string m_name;
        Date m_due_date;
        string m_created_date;
        string m_description;
        long   m_id;
        int    m_status;

    public:
        Task();
        Task(string name);
        ~Task();

        void set_name(string name);
        void set_due_date(string due_date);
        void set_description(string description);
        void set_id(string id);
        void set_status(int status);

        string get_name();
        string get_due_date();
        string get_created_date();
        string get_description();
        int get_id_number();
        int get_status();
};

Task::Task(){
    m_name = "New Name";
    m_due_date = Date();
    m_due_date.set_current_datetime();
};

#endif
