#ifndef CHAT_H
#define CHAT_H

#include <QObject>

class KeysInput;
class Curtains;
class Letter;
class QTimer;
class ChatClient;
class MainWnd;

class Chat : public QObject
{
    Q_OBJECT
public:
    explicit Chat(QObject *parent = 0);
    ~Chat();

signals:

public slots:
    void Show();

private slots:
    void Switch(bool on);
    void ReadLine();
    void NewMsg();

private:
    KeysInput* _keys;
    Curtains* _curtains;
    Letter* _letter;
    QTimer* _autoCurtains;
    ChatClient* _client;
    MainWnd* _dlg;

};

#endif // CHAT_H
