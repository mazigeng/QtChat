#ifndef HOCKEVENT_H
#define HOCKEVENT_H

#include <windows.h>

class HockEvent
{

public:
    HockEvent();
    ~HockEvent();
    virtual bool KeysEvent(long w, long l) = 0;
    virtual bool MouseEvent(long w, long l) = 0;

};

bool InHock();
void UnHock();


#endif // HOCKEVENT_H
