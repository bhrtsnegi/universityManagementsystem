#include <iostream>
#include <mysql.h>
#include <mysqld error.h>
#include <windows.h>
#include <sstream>
using namespace std;

const char *HOST = "localhost";
const char *USER = "root";
const char *PW = " ";
const char *DB = "mydb";

int main()
{
    MYSQL *conn;
    conn = mysql_init(NULL);

    if (!)
        return 0;
}
