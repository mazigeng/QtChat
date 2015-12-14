#include "hockevent.h"



#include <stdio.h>
#include <windows.h>
#include <QList>

#include <QDebug>


static HHOOK g_ms_hook = 0;
static HHOOK g_kb_hook = 0;
static QList<HockEvent*> g_objs;

LRESULT CALLBACK kb_proc (int code, WPARAM w, LPARAM l)
{
    if(w==WM_KEYDOWN || w==WM_KEYUP)
    {
        foreach(HockEvent* obj, g_objs)
        {
            if(obj->KeysEvent(w,((PKBDLLHOOKSTRUCT)l)->vkCode))
                return 0;
        }
    }

    return CallNextHookEx (g_kb_hook, code, w, l);
}
LRESULT CALLBACK ms_proc (int code, WPARAM w, LPARAM l)
{
    foreach(HockEvent* obj, g_objs)
    {
        if(obj->MouseEvent(w,l))
            return 0;
    }

    return CallNextHookEx (g_ms_hook, code, w, l);
}

bool InHock()
{

    g_kb_hook = SetWindowsHookEx (WH_KEYBOARD_LL,kb_proc,GetModuleHandle (NULL),0);
    //g_ms_hook = SetWindowsHookEx (WH_MOUSE_LL, ms_proc,GetModuleHandle(NULL),0);

    if (g_kb_hook == NULL || g_ms_hook == NULL)
    {
        return false;
    };
    qDebug() << "hock";
    return true;
}

void UnHock()
{
    UnhookWindowsHookEx(g_kb_hook);
}



HockEvent::HockEvent()
{
    g_objs.append(this);
}

HockEvent::~HockEvent()
{
    g_objs.removeOne(this);
}
