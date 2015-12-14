#ifndef MAINWND_H
#define MAINWND_H

#include <QDialog>

namespace Ui {
class MainWnd;
}

class MainWnd : public QDialog
{
    Q_OBJECT

public:
    explicit MainWnd(QWidget *parent = 0);
    ~MainWnd();

private:
    Ui::MainWnd *ui;
};

#endif // MAINWND_H
