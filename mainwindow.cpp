#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auth_form = new CWindow();
    auth_helper = new CAuthorization();
    auth_helper->set_connection();
    ui->log_info->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete auth_form;
    delete auth_helper;
}


void MainWindow::on_pushButton_clicked()
{
    const auto copy_settings = [&](){
        auth_form->setMinimumWidth(this->minimumWidth());
        auth_form->setMaximumWidth(this->maximumWidth());
        auth_form->setMinimumHeight(this->minimumHeight());
        auth_form->setMaximumHeight(this->maximumHeight());
        auth_form->setGeometry(this->x(), this->y(), this->width(), this->height());
    };
    if(!auth_helper->authorize(QString(this->ui->login_form->text()),QString(this->ui->pass_form->text())))
    {
        ui->login_form->clear();
        ui->pass_form->clear();
        ui->log_info->show();
        return;
   // qDebug("logged");
    }
    copy_settings();
    this->close();
    auth_form->show();

}

