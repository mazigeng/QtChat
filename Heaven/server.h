#ifndef SERVER_H
#define SERVER_H

#include <QObject>

class ChatServer;

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);

signals:

public slots:


private:
    ChatServer* _server;

};

#endif // SERVER_H
