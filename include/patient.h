#ifndef PATIENT_H
#define PATIENT_H

#include "user.h"

class Patient : public User
{
private:
    /********* attributs **********/
    std::string medicalHistory;

public:
    /********** empty constructor *******/
    Patient();

    /********* parametrized constructor *******/
    Patient ( int _id,
              std::string _name,
              std::string _address,
              std::string _phoneNumber,
              std::string _medicalHistory,
              loginState _state
            );

    /************* getter and setter **********/
    std::string getMedicalHistory() const;
    void setMedicalHistory(std::string medicalHistory);

    /*********** comparison operator  *********/
    bool operator ==(const Patient &other);

    /************* static functions ***********/
    static Patient login(int _id, std::string _password);

    /********* fundemental functions  *********/
    bool login() override;
    void bookAppointment();
    void viewMedicalHistory();
    
    /********** helper functions *************/
    void displayInfo() const override;
};

#endif