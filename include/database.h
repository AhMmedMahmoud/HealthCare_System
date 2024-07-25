#ifndef DATABASE_H
#define DATABASE_H

#include "patient.h"
#include "doctor.h"
#include "admin.h"
#include "appointment.h"
#include <vector>
#include <map>

class Database
{
private:
    /********* attributes **********/
    int noOfPatients;
    int noOfDoctors;
    int noOfAdmins;
    int noOfAppointments;

    std::vector<Patient> patients;
    std::vector<Doctor> doctors;
    std::vector<Admin> admins;
    std::vector<Appointment> appointments;
    
    std::map<int, std::string> patientsPasswords;
    std::map<int, std::string> doctorsPasswords;
    std::map<int, std::string> adminsPasswords;

public:
    /********* constructor **********/
    Database();

    /****** setter and getter *******/
    int getNoOfPatients();
    int getNoOfDoctors();
    int getNoOfAdmins();
    int getNoOfAppointments();
    
    /************ fundemenral functions ***********/
    void increaseNoOfPatient();
    void increaseNoOfDoctor();
    void increaseNoOfAdmins();
    void increaseNoOfAppointments();

    Patient verifyPatient(int _id, std::string _password);
    bool isVerifiedPatient(int _id, std::string _password);
    
    Doctor verifyDoctor(int _id, std::string _password);
    bool isVerifiedDoctor(int _id, std::string _password);

    Admin verifyAdmin(int _id, std::string _password);   
    bool isVerifiedAdmin(int _id, std::string _password);

    void viewAvailableDoctors();
    void viewAppointments();
    void viewPatients();
    void viewDoctors();
    void viewMedicalHistory(int patientId);
    void addAppointment(int patientId, int doctorId, int slotNumber);
    void addPatient( Admin& admin,
                     std::string name,
                     std::string address,
                     std::string phoneNumber,
                     std::string medicalHistory,
                     std::string password
                  );
    int findAppointment(int id);
    int findPatient(int id);
    int findDoctor(int id);
    void addDoctor( Admin& admin,
                    std::string name,
                    std::string address,
                    std::string phoneNumber,
                    std::string speciality,
                    std::vector<TimeSlot> availableSlots,
                    std::string password
                  );
    void modifyPatientName(int patientId, std::string newValue);
    void modifyPatientAddress(int patientId, std::string newValue);
    void modifyPatientPhoneNumber(int patientId, std::string newValue);
    void modifyPatientMedicalReport(int patientId, std::string newValue);
    void modifyDoctorName(int doctorId, std::string newValue);
    void modifyDoctorAddress(int doctorId, std::string newValue);
    void modifyDoctorPhoneNumber(int doctorId, std::string newValue);
    void modifyAppointmentStatus(int index, appointmentStatus state);
    
};

#endif