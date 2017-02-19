#ifndef DBHANDLER_H
#define DBHANDLER_H
#include <QString>
#include <QtSql>

class dbhandler
{
public:
    dbhandler();
    bool connect(QString host,QString dbName,QString userName,QString pwd);
    int operation ();
    static dbhandler* getInstance()
    {
        if(! onlydb) onlydb = new dbhandler();
        return onlydb;
    }
    QSqlDatabase db;
private:
    static dbhandler* onlydb;

};

#endif // DBHANDLER_H
