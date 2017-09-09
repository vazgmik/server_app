#include <include/admin.h>
#include <QxOrm_Impl.h>

QX_REGISTER_CPP( Admin ) // This macro is necessary to register 'admin' class in QxOrm context

namespace qx {
    template <> void register_class(QxClass<Admin> & t)
    {
        // 'person' C++ class is mapped to 't_admin' database table
        t.setName("t_admin");
        // Register 'Admin::id' <=> primary key in your database
        t.id(& Admin::id, "id");
        // Register 'Admin::firstName' property mapped to 'first_name' database column name
        t.data(& Admin::firstName, "first_name");
        // Register 'Admin::lastName' property mapped to 'last_name' database column name
        t.data(& Admin::lastName, "last_name");
        // Register 'Admin::birthDate' property mapped to 'birth_date' database column name
        t.data(& Admin::birthDate, "birth_date");
    }
}
