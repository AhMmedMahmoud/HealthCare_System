#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "accessLevel.h"

class Admin : public User
{
private:
    /********* attributs **********/
    accessLevel access;

public:
    /********** empty constructor *******/
    Admin();

    /********* parametrized constructor *******/
    Admin ( int _id,
              std::string _name,
              std::string _address,
              std::string _phoneNumber,
              accessLevel _accessLevel,
              loginState _state
            );

    /*********** getters and setters **********/
    accessLevel getAcessLevel();

    /*********** comparison operator  *********/
    bool operator ==(const Admin &other);

    /********** static functions **********/
    static Admin login(int _id, std::string _password);
    
    /********* fundemental functions  *********/
    bool login() override;
    void addPatient();
    void addDoctor();
    void managePatientAccount();
    void manageDoctorAccount();

    /********** helper functions *************/
    void displayInfo() const override;
};

#endif