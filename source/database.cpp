#include "../include/database.h"
#include <chrono>  
#include <ctime> 

/********* constructor **********/
Database::Database() : noOfPatients(0), noOfAdmins(0), noOfDoctors(0), noOfAppointments(0)
{
    Patient p1( ++noOfPatients,
                "ahmed mahmoud",
                "cairo",
                "01229822560",
                "diabets level: 3",
                loginState::LOGIN_VERIFIED
                );
                
    Patient p2( ++noOfPatients, 
                "ali tamer",
                "giza",
                "01229822561",
                "diabets level: 2",
                loginState::LOGIN_VERIFIED
              );

    patients.push_back(p1);
    patients.push_back(p2);

    patientsPasswords[1] = "1111";
    patientsPasswords[2] = "2222";

    Doctor d1( ++noOfDoctors, 
               "magdi yacoub",
               "alex",
               "01229822562",
               "Heart",
               loginState::LOGIN_VERIFIED,
               {TimeSlot::SLOT_1, TimeSlot::SLOT_4}
             );
    
    Doctor d2( ++noOfDoctors, 
               "ahmed abd-elatief",
               "cairo",
               "01229822563",
               "dential",
               loginState::LOGIN_VERIFIED,
               {TimeSlot::SLOT_2, TimeSlot::SLOT_6}
            );

    doctors.push_back(d1);
    doctors.push_back(d2);
    
    doctorsPasswords[1] = "3333";
    doctorsPasswords[2] = "4444";

    Admin a1( ++noOfAdmins, 
            "magdi yacoub",
            "alex",
            "01229822562",
            accessLevel::Administrator,
            loginState::LOGIN_VERIFIED
            );
    
    admins.push_back(a1);

    adminsPasswords[1] = "5555";
}

/****** setter and getter *******/
int Database::getNoOfPatients() {return noOfPatients;}
int Database::getNoOfDoctors() {return noOfDoctors;}
int Database::getNoOfAdmins() {return noOfAdmins;}
int Database::getNoOfAppointments() {return noOfAppointments;}

/************ fundemenral functions ***********/
void Database::increaseNoOfPatient() {noOfPatients++;}
void Database::increaseNoOfDoctor() {noOfDoctors++;}
void Database::increaseNoOfAdmins() {noOfAdmins++;}
void Database::increaseNoOfAppointments() {noOfAppointments++;}

Patient Database::verifyPatient(int _id, std::string _password)
{
    Patient _result;

    auto itr = patientsPasswords.find(_id);
    if(itr != patientsPasswords.end() && itr->second == _password)
    {
        for(int i = 0; i < noOfPatients; i++)
        {
            if(patients[i].getId() == itr->first)
            {
                _result = patients[i];
                break;
            }
        }
    }
    
    return _result;
}

bool Database::isVerifiedPatient(int _id, std::string _password)
{
    bool _result = false;

    auto itr = patientsPasswords.find(_id);
    if(itr != patientsPasswords.end() && itr->second == _password)
    {
        for(int i = 0; i < noOfPatients; i++)
        {
            if(patients[i].getId() == itr->first)
            {
                _result = true;
                break;
            }
        }
    }

    return _result;
}

Doctor Database::verifyDoctor(int _id, std::string _password)
{
    Doctor _result;

    auto itr = doctorsPasswords.find(_id);
    if(itr != doctorsPasswords.end() && itr->second == _password)
    {
        for(int i = 0; i < noOfDoctors; i++)
        {
            if(doctors[i].getId() == itr->first)
            {
                _result = doctors[i];
                break;
            }
        }
    }
    
    return _result;
}

bool Database::isVerifiedDoctor(int _id, std::string _password)
{
    bool _result = false;

    auto itr = doctorsPasswords.find(_id);
    if(itr != doctorsPasswords.end() && itr->second == _password)
    {
        for(int i = 0; i < noOfDoctors; i++)
        {
            if(doctors[i].getId() == itr->first)
            {
                _result = true;
                break;
            }
        }
    }

    return _result;
}

Admin Database::verifyAdmin(int _id, std::string _password)
{
    Admin _result;

    auto itr = adminsPasswords.find(_id);
    if(itr != adminsPasswords.end() && itr->second == _password)
    {
        for(int i = 0; i < noOfAdmins; i++)
        {
            if(admins[i].getId() == itr->first)
            {
                _result = admins[i];
                break;
            }
        }
    }
    
    return _result;
}

bool Database::isVerifiedAdmin(int _id, std::string _password)
{
    bool _result = false;

    auto itr = adminsPasswords.find(_id);
    if(itr != adminsPasswords.end() && itr->second == _password)
    {
        for(int i = 0; i < noOfPatients; i++)
        {
            if(admins[i].getId() == itr->first)
            {
                _result = true;
                break;
            }
        }
    }

    return _result;
}

void Database::viewAvailableDoctors()
{
    std::cout << "---------------------------------\n";
    for(int i = 0; i < doctors.size(); i++) {
        std::cout << "Dr: " <<doctors[i].getName() << "\n";
        std::cout << "id of doctor: " << doctors[i].getId() << "\n";
        std::cout << "Speciality: " << doctors[i].getSpeciality() << "\n";
        doctors[i].displayAvailableSlots();
        std::cout << "---------------------------------\n";
    }
}

void Database::addAppointment(int patientId, int doctorId, int slotNumber)
{
    for(int i = 0; i < noOfDoctors; i++) {
        if(doctors[i].getId() == doctorId) {
           if( doctors[i].isAvailable(static_cast<TimeSlot>(slotNumber)) ) {
              
            auto now = std::chrono::system_clock::now();  
            std::time_t t = std::chrono::system_clock::to_time_t(now); // Convert to time_t  
            std::tm* currentTime = std::localtime(&t); // Convert to local time  

            // Extract day, month, and year  
            int day = currentTime->tm_mday;        // Day of the month (1-31)  
            int month = currentTime->tm_mon + 1;   // Month (0-11, hence +1)  
            int year = currentTime->tm_year + 1900; // Year since 1900  
            
            Appointment appointment( ++noOfAppointments,
                                     Date(day, month, year),
                                     static_cast<TimeSlot>(slotNumber),
                                     appointmentStatus::Pending,
                                     "consultation",
                                     patientId,
                                     doctorId
                                   );
            
            appointments.push_back(appointment);
           }
        }
    }
}

void Database::viewAppointments()
{
    for(int i = 0; i < appointments.size(); i++) {
        appointments[i].displayInfo();
    }
}

void Database::modifyPatientName(int patientId, std::string newValue) {
    for(auto & patient : patients) {
        if(patient.getId() == patientId) {
            patient.setName(newValue);
        }
    }
}

void Database::modifyPatientAddress(int patientId, std::string newValue) {
    for(auto & patient : patients) {
        if(patient.getId() == patientId) {
            patient.setAddress(newValue);
        }
    }
}

void Database::modifyPatientPhoneNumber(int patientId, std::string  newValue) {
    for(auto & patient : patients) {
        if(patient.getId() == patientId) {
            patient.setPhoneNumber(newValue);
        }
    }
}

void Database::modifyPatientMedicalReport(int patientId, std::string newValue) {
    for(auto & patient : patients) {
        if(patient.getId() == patientId) {
            patient.setMedicalHistory(newValue);
        }
    }
}

void Database::modifyDoctorName(int doctorId, std::string newValue) {
    for(auto & doctor : doctors) {
        if(doctor.getId() == doctorId) {
            doctor.setName(newValue);
        }
    }
}

void Database::modifyDoctorAddress(int doctorId, std::string newValue) {
    for(auto & doctor : doctors) {
        if(doctor.getId() == doctorId) {
            doctor.setAddress(newValue);
        }
    }
}

void Database::modifyDoctorPhoneNumber(int doctorId, std::string  newValue) {
    for(auto & doctor : doctors) {
        if(doctor.getId() == doctorId) {
            doctor.setPhoneNumber(newValue);
        }
    }
}

void Database::viewPatients() {
    std::cout << "--------------------------\n";
    
    for(const auto& patient : patients) {
        patient.displayInfo();
        std::cout << "--------------------------\n";
    }
}

void Database::viewDoctors() {
    std::cout << "--------------------------\n";
    
    for(const auto& doctor : doctors) {
        doctor.displayInfo();
        std::cout << "--------------------------\n";
    }
}

void Database::viewMedicalHistory(int patientId) {
    
    for(const auto& patient : patients) {
        if(patientId == patient.getId()) {
            std::cout << patient.getMedicalHistory() << "\n";
            break;
        }
    }
}
void Database::addPatient(  Admin& admin,
                            std::string name,
                            std::string address,
                            std::string phoneNumber,
                            std::string medicalHistory,
                            std::string password
                         ) 
{
    if( admin.getLoginState() == loginState::LOGIN_VERIFIED &&
        admin.getAcessLevel() == accessLevel::Administrator
      ) 
    {
        Patient patient( ++noOfPatients,
                         name,
                         address, 
                         phoneNumber, 
                         medicalHistory, 
                         loginState::LOGIN_VERIFIED
                       );
        
        patients.push_back(patient);

        patientsPasswords[noOfPatients] = password;
    }
}

void Database::addDoctor( Admin& admin,
                          std::string name,
                          std::string address,
                          std::string phoneNumber,
                          std::string speciality,
                          std::vector<TimeSlot> availableSlots,
                          std::string password
                        )
{
    if( admin.getLoginState() == loginState::LOGIN_VERIFIED &&
        admin.getAcessLevel() == accessLevel::Administrator
      ) 
    {
        Doctor doctor( ++noOfDoctors,
                       name,
                       address, 
                       phoneNumber, 
                       speciality, 
                       loginState::LOGIN_VERIFIED,
                       availableSlots
                     );
        
        doctors.push_back(doctor);

        doctorsPasswords[noOfDoctors] = password;
    }
}

int Database::findAppointment(int id) {
    int _result = -1;
    
    for(int i=0; i<noOfAppointments; i++) {
        if(id == appointments[i].getId()) {
            _result = i;
            break;
        }
    }

    return _result;
}

int Database::findPatient(int id) {
    int _result = -1;
    
    for(int i=0; i<noOfPatients; i++) {
        if(id == patients[i].getId()) {
            _result = i;
            break;
        }
    }

    return _result;
}

int Database::findDoctor(int id) {
    int _result = -1;
    
    for(int i=0; i<noOfDoctors; i++) {
        if(id == doctors[i].getId()) {
            _result = i;
            break;
        }
    }

    return _result;
}

void Database::modifyAppointmentStatus(int index, appointmentStatus state) {
    appointments[index].setStatus(state);
}