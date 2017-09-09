TEMPLATE = subdirs

SUBDIRS = \
            fcgi \
            orm \
            api/blapi

fcgi.subdir = modules/fcgi_module
orm.subdir = modules/orm_module
bl_api.subdir = api
