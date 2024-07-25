#include "../include/appointment.h"

/********** empty constructor ********/
Appointment::Appointment() : id(0),
                             date(Date()),
                             time(Time()),
                             slot(TimeSlot::SLOT_0),
                             status(appointmentStatus::Pending),
                             reason("null"),
                             patientId(0),
                             doctorId(0)
{}

/****** parametrized construcot ******/
Appointment::Appointment( int _id,
                          Date _date,
                          TimeSlot _slot,
                          appointmentStatus _status,
                          std::string _reason,
                          int _patientId,
                          int _doctorId
                        ) : id(_id),
                            date(_date),
                            slot(_slot),
                            status(_status),
                            reason(_reason),
                            patientId(_patientId),
                            doctorId(_doctorId)
{
    switch(slot)
    {
        case TimeSlot::SLOT_1 :
            time.setHour(10);
            time.setMinute(0);
        break;

        case TimeSlot::SLOT_2 :
            time.setHour(11);
            time.setMinute(0);
        break;

        case TimeSlot::SLOT_3 :
            time.setHour(12);
            time.setMinute(0);
        break;

        case TimeSlot::SLOT_4 :
            time.setHour(1);
            time.setMinute(0);
        break;

        case TimeSlot::SLOT_5 :
            time.setHour(2);
            time.setMinute(0);
        break;

        case TimeSlot::SLOT_6 :
            time.setHour(3);
            time.setMinute(0);
        break;
    }
}


/********* getter and setter **********/
int Appointment::getId() {return id;}
Date Appointment::getDate() {return date;}
Time Appointment::getTime() {return time;}
appointmentStatus Appointment::getStatus() {return status;}
std::string Appointment::getReason() {return reason;}
int Appointment::getPatientId() {return patientId;}
int Appointment::getDoctorId() {return doctorId;}
void Appointment::setId(int id) {this->id = id;}
void Appointment::setDate(Date date) {this->date = date;}
void Appointment::setTime(Time time) {this->time = time;}
void Appointment::setStatus(appointmentStatus status) {this->status = status;}
void Appointment::setReason(std::string reason) {this->reason = reason;}
void Appointment::setPatientId(int patientId) {this->patientId = patientId;}
void Appointment::setDoctorID(int doctorId) {this->doctorId = doctorId;}

/********* comparison operator  *******/
bool Appointment::operator ==(const Appointment &other)
{
    bool _result = false;

    if( id == other.id &&
        date == other.date &&
        time == other.time &&
        status == other.status && 
        reason == other.reason && 
        patientId == other.patientId &&
        doctorId == other.doctorId
      )
        _result = true;
    else
        _result = false;

    return _result;
}

/********* fundemental functions  *********/
void Appointment::displayInfo() const
{
   std::cout << "id: " << id << "\n";
   date.displayInfo();
   
    switch(slot)
    {
        case TimeSlot::SLOT_1 : std::cout << "slot: slot1\n"; break;
        case TimeSlot::SLOT_2 : std::cout << "slot: slot2\n"; break;
        case TimeSlot::SLOT_3 : std::cout << "slot: slot3\n"; break;
        case TimeSlot::SLOT_4 : std::cout << "slot: slot4\n"; break;
        case TimeSlot::SLOT_5 : std::cout << "slot: slot5\n"; break;
        case TimeSlot::SLOT_6 : std::cout << "slot: slot6\n"; break;
    }

    switch(status)
    {
        case appointmentStatus::Pending : std::cout << "status: Pending\n"; break;
        case appointmentStatus::Confirmed : std::cout << "status: Confirmed\n"; break;
        case appointmentStatus::Completed : std::cout << "status: Completed\n"; break;
        case appointmentStatus::Cancelled : std::cout << "status: Cancelled\n"; break;
        case appointmentStatus::NoShow : std::cout << "status: NoShow\n"; break;
    }

    std::cout << "Reason: " << reason << "\n";
    std::cout << "PatientId: " << patientId << "\n";
    std::cout << "DoctorId: " << doctorId << "\n";
}