#include "mainwnd.h"
#include "ui_mainwnd.h"

MainWnd::MainWnd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWnd)
{
    ui->setupUi(this);
}

MainWnd::~MainWnd()
{
    delete ui;
}
