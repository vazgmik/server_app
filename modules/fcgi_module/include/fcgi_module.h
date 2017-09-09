#ifndef FCGI_MODULE_H
#define FCGI_MODULE_H

#include <iostream>
#include <QCoreApplication>
#include <QHostAddress>
#include <QTimer>

#include <signal.h>
#include <qfcgi.h>


class QFCgiApp : public QCoreApplication {
  Q_OBJECT

public:
  QFCgiApp(int argc, char *argv[]);

private slots:
  void onNewRequest(QFCgiRequest *request);

private:
  QFCgi *fcgi;
};

static void quit_handler(int signal) {
  qApp->quit();
}

#endif // FCGI_MODULE_H
