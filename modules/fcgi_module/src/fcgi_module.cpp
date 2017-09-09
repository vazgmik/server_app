#include "../include/fcgi_module.h"

QFCgiApp::QFCgiApp(int argc, char *argv[]) : QCoreApplication(argc, argv) {
    this->fcgi = new QFCgi(this);

    // Connect to the newRequest signal, the onNewRequest() method
    // is invoked every time a new FastCGI request is available
    connect(this->fcgi, SIGNAL(newRequest(QFCgiRequest*)),
            this, SLOT(onNewRequest(QFCgiRequest*)));

    // confiure the FastCGI application server to listen on localhost, port 9000
    this->fcgi->configureListen(QHostAddress::LocalHost, 9000);

    // start the FastCGI application server
    this->fcgi->start();

    // check the status of the FastCGI application server
    if (!this->fcgi->isStarted()) {
      qCritical() << this->fcgi->errorString();
      QTimer::singleShot(0, this, SLOT(quit()));
    }
}

void QFCgiApp::onNewRequest(QFCgiRequest *request) {
    // You have a new request, this sample implementation will write back
    // a list of all received parameter.

    // request->getOut() is a stream which is used to write back information
    // to the webserver.
    QTextStream ts(request->getOut());

    ts << "Content-Type: plain/text\n";
    ts << "\n";
    ts << QString("Hello from %1\n").arg(this->applicationName());
    ts << "This is what I received:\n";

    //QSqlError daoError = qx::dao::fetch_all(lst_admget);
    Q_FOREACH(QString key, request->getParams()) {
      ts << QString("%1: %2\n").arg(key).arg(request->getParam(key));
    }

    /*for(adm_ptr adm: lst_admget){
      ts << QString("%1: %2 %3 %4\n").arg(adm->id).arg(adm->firstName).arg(adm->lastName).arg(adm->birthDate.toString());
    }*/

    ts.flush();

    // Don't forget to call endRequest() to finalize the request
    request->endRequest(0);
}
