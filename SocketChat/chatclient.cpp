#include "chatclient.h"

#include <QHostAddress>
#include <QDebug>

ChatClient::ChatClient( QObject *parent /* = NULL */ )
    : QTcpSocket( parent )
{
    connect( this, SIGNAL(connected()), this, SLOT(OnConnected()) );
}

ChatClient::~ChatClient()
{
}

void ChatClient::ConnectToServer( const char *ip, quint16 port )
{
    QString strip( ip );
    QHostAddress addr;
    addr.setAddress( strip );
    connectToHost( addr, port );
}

void ChatClient::Close()
{
    disconnectFromHost();
    close();
}



void ChatClient::OnConnected()
{
    qDebug() << "connected";
}
