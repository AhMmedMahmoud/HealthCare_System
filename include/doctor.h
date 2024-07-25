#ifndef DOCTOR_H
#define DOCTOR_H

#include "user.h"
#include "timeSlot.h"
#include <vector>
#include <map>

class Doctor : public User
{
private:
    /********* attributs **********/
    std::string speciality;
    std::map<TimeSlot, bool> availability; // true if available, false otherwise  

public:
    /********** empty constructor *******/
    Doctor();

    /********* parametrized constructor *******/
    Doctor ( int _id,
              std::string _name,
              std::string _address,
              std::string _phoneNumber,
              std::string _speciality,
              loginState _state,
              std::vector<TimeSlot> availableSlots
            );

    /*********** comparison operator  *********/
    bool operator ==(const Doctor &other);

    /************* getter and setter **********/
    std::string getSpeciality();
    void setSpeciality(std::string speciality);

    /********** static functions **********/
    static Doctor login(int _id, std::string _password);
    
    /********* fundemental functions  *********/
    bool login() override;

    // Set availability for a specific time slot  
    void setAvailability(TimeSlot slot, bool available);  
  
    // Check availability for a specific time slot  
    bool isAvailable(TimeSlot slot) const;
    
    void updateMedicalReport();
    void cancelAppointment();
    void confirmAppointment();
    void manageSchedule();

    /********** helper functions *************/
    void displayAvailableSlots() const;
    void displayInfo() const override;
};


#endif