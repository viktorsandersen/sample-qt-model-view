#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QDate>

struct Employee {
    QString name;
    QString role;
    QDate employment;

    Employee(const QString& name, const QString& role, QDate employment) :
        name(name),
        role(role),
        employment(employment)
    {}
};

#endif // EMPLOYEE_H
