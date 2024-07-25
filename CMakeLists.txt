cmake_minimum_required(VERSION 3.14)
project(Demo)
set(CMAKE_CXX_STANDARD 14)

add_library(
   Demo

   include/database.h
   include/patient.h
   include/shared.h
   include/state.h
   include/user.h
   include/userType.h
   include/doctor.h
   include/accessLevel.h
   include/admin.h
   include/date.h
   include/time.h
   include/appointment.h
   include/timeSlot.h
   
   source/database.cpp
   source/patient.cpp
   source/shared.cpp
   source/user.cpp
   source/doctor.cpp
   source/admin.cpp
   source/date.cpp
   source/time.cpp
   source/appointment.cpp
)

add_executable(app app.cpp)
target_link_libraries(app Demo)