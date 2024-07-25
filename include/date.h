#ifndef DATE_H
#define DATE_H

class Date
{
private:
    /****** attributes ******/
    int day;
    int month;
    int year;

public:
    /***** parametrized constructor ******/
    Date(int _day, int _month, int _year);

    /******** empty constructor **********/
    Date();

    /******** setter and getter  *********/
    int getDay();
    int getMonth();
    int getYear();
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    /*********** comparison operator  *********/
    bool operator ==(const Date &other);

    /********* fundemental functions  *********/
    void displayInfo() const;
};

#endif