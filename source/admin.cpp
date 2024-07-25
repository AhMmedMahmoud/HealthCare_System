#include "../include/admin.h"
#include "../include/shared.h"

/********** constructor *******/
Admin::Admin() : User()
{}

/********* parametrized constructor *******/
Admin::Admin ( int _id,
                   std::string _name,
                   std::string _address,
                   std::string _phoneNumber,
                   accessLevel _acess,
                   loginState _state
                 ) : User(_id, _name, _address, _phoneNumber, _state, userType::ADMIN),
                     access(_acess)
{}

/********** fundemenal functions **********/
bool Admin::operator ==(const Admin &other)
{
    return User::operator==(other) && access == other.access;
}

Admin Admin::login(int _id, std::string _password)
{
    Admin _result = db.verifyAdmin(_id, _password);
    
    return _result;
}

void Admin::displayInfo() const
{
    User::displayInfo();

    std::cout << "access: ";
    switch(access) {
        case  accessLevel::Administrator: 
            std::cout << "Administrator\n";
        break;

        case accessLevel::Manager:   
            std::cout << "Manager\n";     
        break;

        case accessLevel::Staff:     
            std::cout << "Staff\n";   
        break;

        case accessLevel::ReadOnly:
            std::cout << "ReadOnly\n";
        break;
    }
}

bool Admin::login()
{
    bool _result = false;

    if(getLoginState() != loginState::LOGIN_VERIFIED) {
        int _id;
        std::string _password;

        std::cout << "Enter Id: ";
        std::cin >> _id;
        std::cout << "Enter Password: ";
        std::cin >> _password;
        
        _result =  db.isVerifiedAdmin(_id, _password);
        if(_result)
            setLoginState(loginState::LOGIN_VERIFIED);
    }
    else 
        _result = true;
    
    return _result;
}

void Admin::addPatient() {
    if(getLoginState() == loginState::LOGIN_VERIFIED) {
        std::string name;
        std::string address;
        std::string phoneNumber;
        std::string medicalHistory;
        std::string password;

        std::cout << "Enter Name: ";
        std::getline(std::cin, name);  // This will read the entire line, including spaces

        std::cout << "Enter Address: ";
        std::getline(std::cin, address);  

        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, phoneNumber);  

        std::cout << "Enter Medical History: ";
        std::getline(std::cin, medicalHistory);  

        std::cout << "Enter Password: ";
        std::getline(std::cin, password); 

        db.addPatient( *this,
                    name,
                    address,
                    phoneNumber,
                    medicalHistory,
                    password
                    );
    }
    else {
        std::cout << "You need to log in to access this feature\n";
    }
}

void Admin::addDoctor() {
    if(getLoginState() == loginState::LOGIN_VERIFIED) {
        std::string name;
        std::string address;
        std::string phoneNumber;
        std::string speciality;
        std::string password;

        std::cout << "Enter Name: ";
        std::getline(std::cin, name);  // This will read the entire line, including spaces

        std::cout << "Enter Address: ";
        std::getline(std::cin, address);  

        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, phoneNumber);  

        std::cout << "Enter Speciality: ";
        std::getline(std::cin, speciality);  

        std::cout << "Enter Password: ";
        std::getline(std::cin, password); 

        std::vector<TimeSlot> availableSlots;
        for(int i = 0; i < TimeSlot::SLOT_6; i++) {
            std::cout << "availabe for slot" << i+1 ;
            std::cout << "press Y for Yes or N for No\n";
            std::string _answer;
            std::cin >> _answer;
            if(_answer == "y" || _answer == "y")
                availableSlots.push_back(static_cast<TimeSlot>(i+1));
        }

        db.addDoctor( *this,
                    name,
                    address,
                    phoneNumber,
                    speciality,
                    availableSlots,
                    password
                    );
    }
    else {
        std::cout << "You need to log in to access this feature\n";
    }
}
/*********** getters and setters **********/
accessLevel Admin::getAcessLevel(){ return access;}