#ifndef ADMIN_H
#define ADMIN_H
#include "person.h"
#include "database.h"

using namespace std;

class Admin : public Person
{
public:
    Admin();
    Admin(string tableName);
    ~Admin();
private:
    string _tableName;
};

#endif // ADMIN_H
