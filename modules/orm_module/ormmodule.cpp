#include "ormmodule.h"

bool OrmModule::connectToDb()
{
    qx::QxSqlDatabase::getSingleton()->setDriverName("QSQLITE");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName("/home/vazg/Dev/testQxOrm/test.sqlite");
    qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
    qx::QxSqlDatabase::getSingleton()->setUserName("root");
    qx::QxSqlDatabase::getSingleton()->setPassword("");
    return true;
}

OrmModule::typeLstAdm OrmModule::getAdmins()
{
    typeLstAdm admins;
    QSqlError daoError = qx::dao::fetch_all(admins);
    return admins;
}

OrmModule::OrmModule()
{
    connectToDb();
}
