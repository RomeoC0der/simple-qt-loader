#ifndef CAUTHORIZATION_H
#define CAUTHORIZATION_H
#include <QSqlDatabase>
#include <QSqlDriver>

class CAuthorization
{
public:
    CAuthorization();
    ~CAuthorization();
    void set_connection();
    bool authorize(const QString& login, const QString& password);
    bool authorized(){return this->is_authorized;};
private:
    QSqlDatabase* db{nullptr};
bool is_authorized{false};
};

#endif // CAUTHORIZATION_H
