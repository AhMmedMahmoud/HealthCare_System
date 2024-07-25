#ifndef APPOINTMENT_STATUS_H
#define APPOINTMENT_STATUS_H

enum class appointmentStatus
{  
    Pending,          // The appointment is waiting for confirmation or action.  
    Confirmed,       // The appointment has been confirmed by the patient or provider.  
    Completed,       // The appointment has taken place.  
    Cancelled,       // The appointment has been cancelled by either party.  
    NoShow           // The patient did not attend the appointment.
};

#endif