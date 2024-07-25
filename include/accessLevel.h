#ifndef ACCESS_LEVEL_H
#define ACCESS_LEVEL_H

enum class accessLevel
{
    Administrator,  // Highest level of access  
    Manager,        // Intermediate level of access  
    Staff,          // General staff access  
    ReadOnly,      // Read-only access
};

#endif