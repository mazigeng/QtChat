#include "chatserver.h"

#include <QHostAddress>
#include <QDebug>
#include <QTcpSocket>

ChatServer::ChatServer( QObject *parent /* = NULL */ )
    : QTcpServer( parent )
{
    _mysockets.empty();
}

ChatServer::~ChatServer()
{
    qDeleteAll( _mysockets );
    _mysockets.clear();
}

void ChatServer::Run( quint16 port )
{
    if( !this->listen(QHostAddress::Any, port) )
        qDebug() << "ChatServer listen failed !";
    else
        qDebug() << "Listen start!";
}

void ChatServer::incomingConnection( int handle )
{
    QTcpSocket *mysocket = new QTcpSocket( this );
    mysocket->setSocketDescriptor( handle );
    connect( mysocket, SIGNAL(disconnected()), this, SLOT(clientDisconnected()) );
    connect( mysocket, SIGNAL(readyRead()), this, SLOT(NewMsg()) );
    _mysockets.append( mysocket );

    qDebug() << "New client connected";
}

void ChatServer::clientDisconnected()
{
    qDebug() << "client disconnected !";
    QList<QTcpSocket*>::iterator iter;
    for( iter = _mysockets.begin(); iter != _mysockets.end(); iter++ ) {
        if( -1 == (*iter)->socketDescriptor() ) {
            _mysockets.erase( iter );
            return;
        }
    }
}

void ChatServer::NewMsg()
{
    QTcpSocket *mysocket = (QTcpSocket*)sender();
    QByteArray data = mysocket->readAll();
    qDebug() << QString::fromUtf8(data);

    foreach(QTcpSocket* my, _mysockets)
    {
        qDebug() << "write byte" << my->write(data);
    }
}
