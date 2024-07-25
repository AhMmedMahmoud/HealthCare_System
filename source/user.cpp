#include "../include/user.h"
#include "../include/shared.h"
#include "../include/userType.h"

/*********** getter and setter  ***********/
int User::getId() const {return id;}
std::string User::getName() const {return name;}
std::string User::getAdress() const {return address;}
std::string User::getPhoneNumber() const {return phoneNumber;}
loginState User::getLoginState() const {return state;}
void User::setId(int id){this->id = id;}
void User::setName(std::string name){this->name = name;}
void User::setAddress(std::string address){this->address = address;}
void User::setPhoneNumber(std::string phoneNumber) {this->phoneNumber = phoneNumber;}
void User::setLoginState(loginState state){this->state = state;}

/********** parametrized constructor ********/
User::User( int _id,
            std::string _name,
            std::string _address,
            std::string _phoneNumber,
            loginState _state,
            userType _type
          ) : id(_id),
              name(_name),
              address(_address),
              phoneNumber(_phoneNumber),
              state(_state),
              type(_type) 
{}

/********** empty constructor ********/
User::User(): id(0), 
        name("null"),
        address("null"),
        phoneNumber("null"),
        state(loginState::LOGIN_NOT_REQUESTED),
        type(userType::NOT_DETERMINED)  
{}


/********* fundemental functions *********/
void User::logout(){state = loginState::LOGIN_CANCELLED;}

bool User::operator== (const User &obj)
{
    if( id == obj.id &&
        name == obj.name &&
        address == obj.address &&
        phoneNumber == obj.phoneNumber
        )
        return true;
    else 
        return false;
}


void User::displayInfo() const {
    std::cout << "name: " << name << "\n";
    std::cout << "address: " << address << "\n";
    std::cout << "phone number: " << phoneNumber << "\n";
    std::cout << "state: ";
    switch(state) {
        case loginState::LOGIN_NOT_REQUESTED:
            std::cout << "LOGIN_NOT_REQUESTED\n";
        break;
        
        case loginState::LOGIN_REQUESTED:
            std::cout << "LOGIN_REQUESTED\n";
        break;

        case loginState::LOGIN_VERIFIED:
            std::cout << "LOGIN_VERIFIED\n";
        break;
        
        case loginState::LOGIN_CANCELLED:
            std::cout << "LOGIN_CANCELLED\n";
        break;
    }
    std::cout << "Type: ";
    switch(type) {
        case userType::PATIENT :
            std::cout << "PATIENT\n";
        break;

        case userType::DOCTOR :
            std::cout << "DOCTOR\n";
        break;

        case userType::ADMIN:
            std::cout << "ADMIN\n";
        break;
    }     
}


void User::manageAccount()
{
    if(state == loginState::LOGIN_VERIFIED) {
        int _choice;
        std::string _newValue;

        std::cout << "Press 0 for modify name\n";
        std::cout << "      1 for modify address\n";
        std::cout << "      2 for modify phone number\n";
        std::cout << "      3 for ignore\n";

        std::cin >> _choice;

        switch(_choice) {
            case 0:
                std::cin.ignore(); // Ignore the newline character left in the buffer  
                std::cout << "Enter new value: ";
                std::getline(std::cin, _newValue);  // This will read the entire line, including spaces  

                db.modifyPatientName(getId(), _newValue);
            break;

            case 1:
                std::cin.ignore(); // Ignore the newline character left in the buffer  
                std::cout << "Enter new value: ";
                std::getline(std::cin, _newValue);  // This will read the entire line, including spaces  

                db.modifyPatientAddress(getId(), _newValue);
            break;

            case 2:
                std::cin.ignore(); // Ignore the newline character left in the buffer  
                std::cout << "Enter new value: ";
                std::getline(std::cin, _newValue);  // This will read the entire line, including spaces  

                db.modifyPatientPhoneNumber(getId(), _newValue);
            break;
        }
    }
    else {
        std::cout << "You need to log in to access this feature\n";
    }
}

