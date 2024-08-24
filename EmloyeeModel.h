#ifndef EMPLOYEEMODEL_H
#define EMPLOYEEMODEL_H

#include <QAbstractListModel>
#include <QVector>

#include "Employee.h"
#include <QDate>

class EmployeeModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles {
        Role = Qt::UserRole,
    };

    EmployeeModel(QObject* parent = 0);
    ~EmployeeModel();

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;

private:
    QVector<Employee*> employees;

};

#endif // COUNTRYMODEL_H
