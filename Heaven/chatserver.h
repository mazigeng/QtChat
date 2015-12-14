#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QObject>
#include <QTcpServer>

class ChatServer : public QTcpServer
{
    Q_OBJECT

public:
    ChatServer(QObject *parent = NULL);
    ~ChatServer();

    void Run(quint16 port);

protected:
    void incomingConnection(int handle);

private slots:
    void clientDisconnected();
    void NewMsg();

private:
    quint16             _port;
    QList<QTcpSocket*>  _mysockets;
};



#endif // CHATSERVER_H
