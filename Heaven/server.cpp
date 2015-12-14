#include "server.h"

#include "chatserver.h"

Server::Server(QObject *parent) :
    QObject(parent)
{
    _server = new ChatServer(this);
    _server->Run(14862);
}

