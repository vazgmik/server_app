#ifndef ADMIN_H
#define ADMIN_H

#include <QxOrm.h>

class Admin
{
public:
   quint64 id;
   QString firstName;
   QString lastName;
   QDateTime birthDate;

   Admin() : id(0) { ; }
   virtual ~Admin() { ; }
};

typedef std::shared_ptr<Admin> adm_ptr;

QX_REGISTER_PRIMARY_KEY(Admin, quint64)
QX_REGISTER_HPP(Admin, qx::trait::no_base_class_defined, 0)

#endif // ADMIN_H
