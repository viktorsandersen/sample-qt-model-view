#include "EmloyeeModel.h"


EmployeeModel::EmployeeModel(QObject* parent) :
    QAbstractListModel(parent),
    employees()
{
    employees
              << new Employee("Frank", "Programmer", QDate(2018, 5, 7))
              << new Employee("John", "Robotics", QDate(2020, 2, 5))
              << new Employee("Peter", "Finance", QDate(2021, 4, 6))
              << new Employee("Erik", "Programmer", QDate(2020, 1, 5));
}

EmployeeModel::~EmployeeModel()
{
    qDeleteAll(employees);
}

int EmployeeModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return employees.size();
}

QVariant EmployeeModel::data(const QModelIndex& index, int role) const
{
    const Employee& employee = *employees.at(index.row());

    switch (role) {
    case Qt::DisplayRole:
        return employee.name;

    case Roles::Role:
        return employee.role;

    case Roles::Role+1:
        return employee.employment;

    default:
        return QVariant();
        break;
    }
}
