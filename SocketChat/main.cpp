#include <QApplication>
#include "chat.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Chat* c = new Chat();
    c->Show();

    return a.exec();
    delete c;

}
