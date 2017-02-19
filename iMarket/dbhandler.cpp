#include "dbhandler.h"
#include <QString>
dbhandler* dbhandler::onlydb=NULL;
dbhandler::dbhandler()
{
    db=QSqlDatabase::addDatabase("QMYSQL");
}

bool dbhandler::connect(QString host,QString dbName,QString userName,QString pwd)
{
    /*
     * 输入
     * host       主机
     * dbName     数据库名称
     * userName   用户名字
     * pwd        密码
     * 输出
     * 布尔类型的链接标识
     * */
    db.setHostName(host);
    db.setDatabaseName(dbName);
    db.setUserName(userName);
    db.setPassword(pwd);
    return db.open();
}
