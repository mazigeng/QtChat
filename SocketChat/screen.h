#ifndef SCREEN_H
#define SCREEN_H

#include <QObject>
#include <QList>

class Screen : public QObject
{
    Q_OBJECT
public:
    explicit Screen(QObject *parent = 0);
    void AddLine(QString msg);

signals:

public slots:
    void Show();

protected:
    QList<QString> _msg;

};

#endif // SCREEN_H
