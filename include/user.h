#ifndef USER_H
#define USER_H

#include<iostream>
#include"state.h"
#include"userType.h"

class User
{
private:
    /******** attributes *******/
    int id;
    std::string name;
    std::string address;
    std::string phoneNumber;
    loginState state;
    userType type;

public:
    /*********** getter and setter  ***********/
    int getId() const;
    std::string getName() const;
    std::string getAdress() const;
    std::string getPhoneNumber() const;
    loginState getLoginState() const;
    void setId(int id);
    void setName(std::string name);
    void setAddress(std::string address);
    void setPhoneNumber(std::string phoneNumber);
    void setLoginState(loginState state); 

    /********** parametrized constructor ********/
    User( int _id,
          std::string _name,
          std::string _address,
          std::string _phoneNumber,
          loginState _state,
          userType _type
        );

    /********** empty constructor ********/
    User();

    /*********** comparison operator  *********/
    bool operator== (const User &obj);

    /********* fundemental functions *********/
    virtual bool login() = 0;
    void logout();
    void manageAccount();
    virtual void displayInfo() const;
};


#endif