#include "../include/date.h"
#include<iostream>

/***** parametrized constructor ******/
Date::Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year)
{}

/******** empty constructor **********/
Date::Date() : day(0), month(0), year(0)
{}

/******** setter and getter  *********/
int Date::getDay() {return day;}
int Date::getMonth() {return month;}
int Date::getYear() {return year;}
void Date::setDay(int day) {this->day = day;}
void Date::setMonth(int month) {this->month = month;}
void Date::setYear(int year) {this->year = year;}

/*********** comparison operator  *********/
bool Date::operator ==(const Date &other)
{
    bool _result = false;

    if(day == other.day && month == other.month && year == other.year)
        _result = true;
    else
        _result = false;

    return _result;
}

/********* fundemental functions  *********/
void Date::displayInfo() const
{
   std::cout << "Date: " << day << "/" << month << "/" << year << "\n"; 
}