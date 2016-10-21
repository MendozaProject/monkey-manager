#ifndef DATE_H
#define DATE_H
#pragma once

#include <ctime>
#include <string>

using namespace std;

class Date {

public:
    int DAY;
    int MONTH;
    int YEAR;
    int HOUR;
    int MINUTE;
    int SECOND;

    Date();
    ~Date();
    void set_current_datetime();
    string get_date_string();
    string get_time_string();
};

#endif // DATE_H
