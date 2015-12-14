#include "chat.h"
#include "keysinput.h"
#include "curtains.h"
#include "letter.h"

#include <QDebug>
#include <QTimer>


#include <QCoreApplication>
#include "chatclient.h"
#include "mainwnd.h"

Chat::Chat(QObject *parent) :
    QObject(parent)
{
    InHock();
    _keys = new KeysInput();
    _curtains = new Curtains();
    _letter = new Letter();
    _autoCurtains = new QTimer();
    _autoCurtains->setInterval(1000);
    _autoCurtains->setSingleShot(true);
    _client = new ChatClient();
    _client->ConnectToServer("172.16.3.107", 14862);
    _dlg = new MainWnd();


    connect(_keys, SIGNAL(Switch(bool)), this, SLOT(Switch(bool)), Qt::QueuedConnection);
    connect(_keys, SIGNAL(Enter()), this, SLOT(ReadLine()), Qt::QueuedConnection);
    connect(_autoCurtains, SIGNAL(timeout()), _curtains, SLOT(Show()));
    connect(_keys, SIGNAL(Switch(bool)), _autoCurtains, SLOT(stop()), Qt::QueuedConnection);
    connect(_client, SIGNAL(readyRead()), this, SLOT(NewMsg()));

}

Chat::~Chat()
{
    UnHock();
}

void Chat::Show()
{
    _dlg->show();
    _dlg->raise();
    _dlg->activateWindow();
}


void Chat::Switch(bool on)
{
    if(on)
    {
        _letter->Show();
    }
    else
    {
        _curtains->Show();
    }
}

void Chat::ReadLine()
{
    QTextStream cin(stdin, QIODevice::ReadOnly);
    _client->write(cin.readLine().toUtf8());
    _autoCurtains->start();
}

void Chat::NewMsg()
{
    _letter->AddLine(_client->readAll());
}
