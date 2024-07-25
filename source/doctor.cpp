#include "../include/doctor.h"
#include "../include/shared.h"

/********** constructor *******/
Doctor::Doctor() : User()
{
    // Initialize all slots as not available  
    for (int i = 0; i <= SLOT_6; ++i) {  
        availability[static_cast<TimeSlot>(i)] = false;  
    } 
}

/********* parametrized constructor *******/
Doctor::Doctor ( int _id,
                   std::string _name,
                   std::string _address,
                   std::string _phoneNumber,
                   std::string _speciality,
                   loginState _state,
                   std::vector<TimeSlot> availableSlots
               ) : User(_id, _name, _address, _phoneNumber, _state, userType::DOCTOR),
                   speciality(_speciality)
{
    for(int i = 0; i < availableSlots.size(); i++)
    {
        availability[availableSlots[i]] = true;
    }
}

/************* getter and setter **********/
std::string Doctor::getSpeciality() { return speciality;}
void Doctor::setSpeciality(std::string speciality) {this->speciality = speciality;}

/********** fundemenal functions **********/
bool Doctor::operator ==(const Doctor &other)
{
    return User::operator==(other) && speciality == other.speciality;
}

Doctor Doctor::login(int _id, std::string _password)
{
    Doctor _result = db.verifyDoctor(_id, _password);
    
    return _result;
}

void Doctor::setAvailability(TimeSlot slot, bool available) {  
    if(getLoginState() == loginState::LOGIN_VERIFIED) {
        availability[slot] = available;  
    }
    else {
        std::cout << "You need to log in to access this feature\n";
    }
}  

bool Doctor::isAvailable(TimeSlot slot) const {  
    auto it = availability.find(slot);  
    return it != availability.end() && it->second;  
}

void Doctor::displayAvailableSlots() const
{ 
    if(getLoginState() == loginState::LOGIN_VERIFIED) {
        bool flag = false;
        std::cout << "availability: ";
        for (const auto& slot : availability) {
            if(!flag) {
                std::cout << " Slot " << slot.first << std::endl;  
                flag = true;
            }  
            else {
                std::cout << "               Slot " << slot.first << std::endl;  
            }
        }
    }
    else {
        std::cout << "You need to log in to access this feature\n";
    }  
}

void Doctor::displayInfo() const
{
    User::displayInfo();
    std::cout << "Speciality: " << speciality << "\n";
}

bool Doctor::login()
{
    bool _result = false;

    if(getLoginState() != loginState::LOGIN_VERIFIED) {
        int _id;
        std::string _password;

        std::cout << "Enter Id: ";
        std::cin >> _id;
        std::cout << "Enter Password: ";
        std::cin >> _password;
        
        _result =  db.isVerifiedDoctor(_id, _password);
        if(_result)
            setLoginState(loginState::LOGIN_VERIFIED);
    }
    else 
        _result = true;
    
    return _result;
}

void Doctor::updateMedicalReport() {
    if(getLoginState() == loginState::LOGIN_VERIFIED) {
        int patientId;
        std::cout << "Enter Patient ID: ";
        std::cin >> patientId;

        std::string medicalReport;
        std::cout << "Enter Medical Report: ";
        std::getline(std::cin, medicalReport);  // This will read the entire line, including spaces  

        db.modifyMedicalReport(patientId, medicalReport);
    }
    else {
        std::cout << "You need to log in to access this feature\n";
    }
}

void Doctor::cancelAppointment() {
    if(getLoginState() == loginState::LOGIN_VERIFIED) {
        db.viewAppointments();
        
        std::cout << "Enter Appointment Id to cancel or 0 for ignore\n";
        
        int choice;
        std::cin >> choice;
        
        if(choice != 0) {
            int _result = db.findAppointment(choice);
            if(_result != -1) {
                db.modifyAppointmentStatus(_result, appointmentStatus::Cancelled);
            }
        }
    }
    else {
        std::cout << "You need to log in to access this feature\n";
    }
}

void Doctor::confirmAppointment() {
    if(getLoginState() == loginState::LOGIN_VERIFIED) {
        db.viewAppointments();
        
        std::cout << "Enter Appointment Id to confirm or 0 for ignore\n";
        
        int choice;
        std::cin >> choice;
        
        if(choice != 0) {
            int _result = db.findAppointment(choice);
            if(_result != -1) {
                db.modifyAppointmentStatus(_result, appointmentStatus::Confirmed);
            }
        }
    }
    else {
        std::cout << "You need to log in to access this feature\n";
    }
}

void Doctor::manageSchedule() {
    if(getLoginState() == loginState::LOGIN_VERIFIED) {
        db.viewAppointments();
        
        std::cout << "Enter --> Appointment Id you want to confirm or cancel\n";
        std::cout << "      --> 0 for ignore\n";
        
        int choice;
        std::cin >> choice;
        
        if(choice != 0) {
            int _result = db.findAppointment(choice);
            if(_result != -1) {
                std::cout << "Press --> 1 for confirm\n";
                std::cout << "      --> 2 for cancel\n";
                std::cout << "      --> 0 for ignore\n";

                std::cin >> choice;
                
                if(choice == 1)
                    db.modifyAppointmentStatus(_result, appointmentStatus::Confirmed);
                else if(choice == 2)
                    db.modifyAppointmentStatus(_result, appointmentStatus::Cancelled);
            }
        }
    }
    else {
        std::cout << "You need to log in to access this feature\n";
    }
}
