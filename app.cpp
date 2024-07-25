#include<iostream>
#include "include/patient.h"
#include "include/shared.h"
#include "include/admin.h"

int main()
{
    Patient patient1 = Patient::login(1, "1111");

    patient1.bookAppointment();

    db.viewAppointments();
    
    std::cout << "\n\n\n";
/*
    patient1.manageAccount();

    std::cout << "\n\n\n";

    db.viewPatients();

    Admin admin1 = Admin::login(1, "5555");
    std::cout << static_cast<int>(admin1.getLoginState()) << "\n";

    admin1.addPatient();

    db.viewPatients();
*/

    Doctor doctor1 = Doctor::login(1, "3333");
    std::cout << static_cast<int>(doctor1.getLoginState()) << "\n";

    doctor1.cancelAppointment();

    db.viewAppointments();

    return 0;
}