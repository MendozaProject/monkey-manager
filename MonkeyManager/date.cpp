//#include "date.h"

//Date::Date()
//{

//}

//Date::~Date()
//{

//}

//void Date::set_current_datetime(){
//    time_t currentTime;
//    struct tm *localTime;

//    // Get the current time
//    time(&currentTime);

//    // Convert the current time to the local time
//    localTime = localtime( &currentTime );

//    DAY    = localTime->tm_mday;
//    MONTH  = localTime->tm_mon + 1;
//    YEAR   = localTime->tm_year + 1900;
//    HOUR   = localTime->tm_hour;
//    MINUTE    = localTime->tm_min;
//    SECOND    = localTime->tm_sec;
//}

//string Date::get_date_string(){
//    string date_string = to_string(MONTH)
//            .append("/").append(to_string(DAY))
//            .append("/").append(to_string(YEAR));
//    return date_string;
//}

//string Date::get_time_string(){
//    string time_string = to_string(HOUR)
//            .append(":").append(to_string(MINUTE))
//            .append(":").append(to_string(SECOND));
//    return time_string;
//}

////template<>
////Date::operator=(Date date){
////    swap (this->DAY, date.DAY);
////    swap (this->MONTH, date.MONTH);
////    swap (this->YEAR, date.YEAR);
////    swap (this->HOUR, date.HOUR);
////    swap (this->MINUTE, date.MINUTE);
////    swap (this->SECOND, date.SECOND);
////    return *this;
////}
