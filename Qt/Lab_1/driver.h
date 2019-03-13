#ifndef DRIVER_H
#define DRIVER_H
#include "person.h"

class Driver : public Person
{
public:
    Driver();
    ~Driver();
    void changelp();
};

#endif // DRIVER_H
