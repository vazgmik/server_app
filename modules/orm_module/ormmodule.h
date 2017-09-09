#ifndef ORMMODULE_H
#define ORMMODULE_H

#include <include/admin.h>

class OrmModule
{
private:
    typedef std::vector<adm_ptr> typeLstAdm;

private:
    bool connectToDb();
    typeLstAdm getAdmins();

public:
    OrmModule();
};

#endif // ORMMODULE_H
