#include <QApplication>

#include "server.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Server* s = new Server();

    return a.exec();
    delete s;
}
