#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include<iostream>
#include "date.h"
#include "time.h"
#include "timeSlot.h"
#include "appointmentStatus.h"

class Appointment
{
private:
    /***** attributes *****/
    int id;
    Date date;
    Time time;
    TimeSlot slot;
    appointmentStatus status;
    std::string reason;
    int patientId;
    int doctorId;

public:
    /********** empty constructor ********/
    Appointment();

    /****** parametrized construcot ******/
    Appointment( int _id,
                 Date _date,
                 TimeSlot _slot,
                 appointmentStatus _status,
                 std::string _reason,
                 int _patientId,
                 int _doctorId
               );

    /********* getter and setter **********/
    int getId();
    Date getDate();
    Time getTime();
    int getDuration();
    appointmentStatus getStatus();
    std::string getReason();
    int getPatientId();
    int getDoctorId();
    void setId(int id);
    void setDate(Date date);
    void setTime(Time time);
    void setDuration(int duration);
    void setStatus(appointmentStatus status);
    void setReason(std::string reason);
    void setPatientId(int patientId);
    void setDoctorID(int doctorId);

    /********* comparison operator  *******/
    bool operator ==(const Appointment &other);

    /********* fundemental functions  *********/
    void displayInfo() const;
};

#endif