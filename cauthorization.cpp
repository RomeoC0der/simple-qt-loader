#include "cauthorization.h"
#include <QSqlQuery>
#include <QDebug>
CAuthorization::CAuthorization()
{
db =  new QSqlDatabase();
*db  = db->addDatabase("QMYSQL");
}

CAuthorization::~CAuthorization()
{
    delete db;
}

void CAuthorization::set_connection()
{
    db->setHostName("127.0.0.1");
    db->setPort(3306);
    db->setUserName("root");
    db->setPassword("");
    db->setDatabaseName("users");
   /* db->setHostName("sql4.freemysqlhosting.net");
    db->setPort(3306);
    db->setUserName("sql4423731");
    db->setPassword("hySwiKKufc");
    db->setDatabaseName("sql4423731");*/
    db->open();
   /* if(db->isOpen()){
        qDebug("db is open");
    }*/
}

bool CAuthorization::authorize(const QString &login, const QString &password)
{
    QSqlQuery query;
    query.exec("SELECT * FROM `user`");
    while(query.next())
    {
    QString _login_ = query.value(1).toString();
    QString _password_ = query.value(2).toString();
   /* qDebug() << _login_;
    qDebug() << _password_;*/
    if(_login_.length() != login.length() || _password_.length() != password.length())continue;//some optimization
    if(_login_.compare(login) == 0 && _password_.compare(password) == 0){
      this->is_authorized = true;
      return true;
        }
    }
    this->is_authorized = false;
    return false;
}
