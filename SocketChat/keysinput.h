#ifndef KEYSINPUT_H
#define KEYSINPUT_H

#include <QObject>
#include <QList>
#include "hockevent.h"


class KeysInput : public QObject, public HockEvent
{
    Q_OBJECT
public:
    explicit KeysInput(QObject *parent = 0);

    virtual bool KeysEvent(long w, long l);
    virtual bool MouseEvent(long w, long l);

signals:
    void Switch(bool on);
    void Enter();

public slots:

private:
    QList<long> _OnKeys;


};

#endif // KEYSINPUT_H
