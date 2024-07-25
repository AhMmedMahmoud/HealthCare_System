#include "../include/patient.h"
#include "../include/shared.h"
#include <chrono>  
#include <ctime> 

/********** constructor *******/
Patient::Patient() : User()
{}

/********* parametrized constructor *******/
Patient::Patient ( int _id,
                   std::string _name,
                   std::string _address,
                   std::string _phoneNumber,
                   std::string _medicalHistory,
                   loginState _state
                 ) : User(_id, _name, _address, _phoneNumber, _state, userType::PATIENT),
                     medicalHistory(_medicalHistory)
{}

/********** fundemenal functions **********/
bool Patient::operator ==(const Patient &other)
{
    return User::operator==(other) && medicalHistory == other.medicalHistory;
}

Patient Patient::login(int _id, std::string _password)
{
    Patient _result = db.verifyPatient(_id, _password);
    
    return _result;
}

bool Patient::login()
{
    bool _result = false;

    if(getLoginState() != loginState::LOGIN_VERIFIED) {
        int _id;
        std::string _password;

        std::cout << "Enter Id: ";
        std::cin >> _id;
        std::cout << "Enter Password: ";
        std::cin >> _password;
        
        _result =  db.isVerifiedPatient(_id, _password);
        if(_result)
            setLoginState(loginState::LOGIN_VERIFIED);
    }
    else 
        _result = true;
    
    return _result;
}

void Patient::displayInfo() const
{
    User::displayInfo();
    std::cout << "Medical History: " << medicalHistory << "\n";
}


void Patient::bookAppointment()
{
    if(getLoginState() == loginState::LOGIN_VERIFIED) {
        db.viewAvailableDoctors();
        
        int doctorId;
        int slotNumber;

        std::cout << "\nEnter Doctor Id: ";
        std::cin >> doctorId;
        std::cout << "Enter Slot Number: ";
        std::cin >> slotNumber;

        db.addAppointment(getId(), doctorId, slotNumber);
    }
    else {
        std::cout << "You need to log in to access this feature\n";
    }
}

void Patient::viewMedicalHistory() {
    db.viewMedicalHistory(getId());
}

/************* getter and setter **********/
std::string Patient::getMedicalHistory() const {return medicalHistory;}

void Patient::setMedicalHistory(std::string medicalHistory) {
    this->medicalHistory = medicalHistory;
}