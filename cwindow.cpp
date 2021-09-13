#include "cwindow.h"
#include "ui_cwindow.h"
#include "c_inject.h"
CWindow::CWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CWindow)
{
    ui->setupUi(this);
}

CWindow::~CWindow()
{
    delete ui;
}

void CWindow::on_pushButton_clicked()
{
    _inject_->inject_to_csgo();
}

