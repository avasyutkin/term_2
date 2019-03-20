#include "admin.h"
#include "person.h"
#include "database.h"

using namespace std;

Admin::Admin()
{

}

Admin::Admin(string tableName)
{
    _tableName=tableName;
    DataBase a;
    a.usertovector(_tableName);
}

Admin::~Admin()
{

}
