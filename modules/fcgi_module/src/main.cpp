#include "include/fcgi_module.h"

int main(int argc, char *argv[]) {
  QFCgiApp app(argc, argv);
  struct sigaction sa;

  memset(&sa, 0, sizeof(struct sigaction));
  sa.sa_handler = quit_handler;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_RESTART;

  if (sigaction(SIGHUP, &sa, 0) != 0 ||
      sigaction(SIGTERM, &sa, 0) != 0 ||
      sigaction(SIGINT, &sa, 0) != 0) {
    perror(argv[0]);
    return 1;
  }

  return app.exec();
}
