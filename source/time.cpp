#include "../include/time.h"
#include <iostream>

/****** parametrized constructor *******/
Time::Time(int _hour, int _minute)
{
    if(_hour <= 12 && hour >= 0 && _minute >= 0 && _minute <= 60) {
        hour = _hour;
        minute = _minute;
    }
    else {
        hour = 0;
        minute = 0;
    }
}

/********** empty constructor **********/
Time::Time() : hour(0), minute(0)
{}

/******** getter and setter  ***********/
int Time::getHour() {return hour;}
int Time::geyMinute() {return minute;}
void Time::setHour(int hout) {this->hour = hour;}
void Time::setMinute(int minute) {this->minute = minute;}

/******** fundemental functions ********/
void Time::displayInfo()
{
    std::cout << "Time: " <<hour << ":" << minute << "\n";
}

/********* comparison operator  ********/
bool Time::operator== (const Time& other)
{
    bool _result = false;

    if(hour == other.hour && minute == other.minute)
        _result =  true;
    else 
        _result =  false;

    return _result;
}