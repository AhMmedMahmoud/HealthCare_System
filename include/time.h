#ifndef TIME_H
#define TIME_H

class Time
{
private:
    /****** attributes ********/
    int hour;
    int minute;

public:
    /****** parametrized constructor *******/
    Time(int _hour, int _minute);

    /********** empty constructor **********/
    Time();
    
    /******** getter and setter  ***********/
    int getHour();
    int geyMinute();
    void setHour(int hout);
    void setMinute(int minute);
    
    /******** fundemental functions ********/
    void displayInfo();

    /********* comparison operator  ********/
    bool operator== (const Time& other);
};

#endif