#include "keysinput.h"

#include <QDebug>
#include <QMap>

KeysInput::KeysInput(QObject *parent) :
    QObject(parent)
{
    _OnKeys.append(162);
    _OnKeys.append(164);
    _OnKeys.append(97);
    _OnKeys.append(105);
}

bool KeysInput::KeysEvent(long w, long l)
{
    if(w == WM_KEYDOWN)
    {
        if(l == 13)
        {
            emit Enter();
        }
    }



    static QMap<long, bool> keyFlag;
    if(_OnKeys.contains(l))
    {
        static bool flag = false;
        if(w == WM_KEYDOWN)
        {
            if(!flag)
            {
                keyFlag[l] = true;
                if(keyFlag.size() == _OnKeys.size())
                {
                    flag = true;
                    emit Switch(true);
                }
            }
        }
        else
        {
            keyFlag.remove(l);
            if (flag)
            {
                flag = false;
                emit Switch(false);
            }
        }
    }
    return false;
}

bool KeysInput::MouseEvent(long w, long l)
{
    return false;
}
