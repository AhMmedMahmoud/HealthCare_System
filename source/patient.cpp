#include "../include/patient.h"
#include "../include/shared.h"
#include <chrono>
#include <ctime>

/********** Constructor **********/
Patient::Patient() : User() {}

/********* Parameterized Constructor *********/
Patient::Patient(int _id, std::string _name, std::string _address, std::string _phoneNumber, std::string _medicalHistory, loginState _state)
    : User(_id, _name, _address, _phoneNumber, _state, userType::PATIENT), medicalHistory(_medicalHistory) {}

/********** Fundamental Functions **********/
bool Patient::operator==(const Patient &other) {
    return User::operator==(other) && medicalHistory == other.medicalHistory;
}

Patient Patient::login(int _id, std::string _password) {
    return db.verifyPatient(_id, _password);
}

bool Patient::login() {
    if (getLoginState() != loginState::LOGIN_VERIFIED) {
        int _id;
        std::string _password;

        std::cout << "Enter Id: ";
        if (!(std::cin >> _id)) {
            std::cout << "Invalid input! Please enter a valid Id.\n";
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining input
            return false;
        }

        std::cout << "Enter Password: ";
        std::cin >> _password;

        bool _result = db.isVerifiedPatient(_id, _password);
        if (_result) {
            setLoginState(loginState::LOGIN_VERIFIED);
        }
        return _result;
    }
    return true; // Already logged in
}

void Patient::displayInfo() const {
    User::displayInfo();
    std::cout << "Medical History: " << medicalHistory << "\n";
}

void Patient::bookAppointment() {
    if (getLoginState() == loginState::LOGIN_VERIFIED) {
        db.viewAvailableAppointments();
        
        int doctorId;
        int slotNumber;

        std::cout << "\nEnter Doctor Id: ";
        if (!(std::cin >> doctorId)) {
            std::cout << "Invalid input! Please enter a valid Doctor Id.\n";
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining input
            return;
        }

        std::cout << "Enter Slot Number: ";
        if (!(std::cin >> slotNumber)) {
            std::cout << "Invalid input! Please enter a valid Slot Number.\n";
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining input
            return;
        }

        db.addAppointment(getId(), doctorId, slotNumber);
    } else {
        std::cout << "You need to log in to access this feature\n";
    }
}

void Patient::viewMedicalHistory() {
    db.viewMedicalHistory(getId());
}

/************* Getter and Setter **********/
std::string Patient::getMedicalHistory() const {
    return medicalHistory;
}

void Patient::setMedicalHistory(std::string medicalHistory) {
    this->medicalHistory = medicalHistory;
}
