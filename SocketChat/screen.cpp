#include "screen.h"
#include <QTextStream>
#include <stdlib.h>
#include <QDebug>

Screen::Screen(QObject *parent) :
    QObject(parent)
{
}

void Screen::AddLine(QString msg)
{
    _msg.append(msg);
}

void Screen::Show()
{
    system("cls");
    foreach(QString s, _msg)
    {
        qDebug() << s;
    }
}
