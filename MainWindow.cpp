#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QItemSelectionModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    countryModel()
{
    ui->setupUi(this);
    setWindowTitle("Model / View sample - Employees");

    ui->countryListView->setModel(&countryModel);

    QItemSelectionModel* selectionModel = ui->countryListView->selectionModel();
    connect(selectionModel, &QItemSelectionModel::selectionChanged,
            this, &MainWindow::onSelectionChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected)
{
    Q_UNUSED(deselected)

    QModelIndexList list = selected.indexes();
    const QModelIndex& index = list.first();

    QString countryName = index.data(Qt::DisplayRole).toString();
    ui->countryNameLabel->setText(countryName);

    QString countryCapital = index.data(EmployeeModel::Role).toString();
    ui->countryCapitalLabel->setText(countryCapital);

    QString countryDate = index.data(EmployeeModel::Role+1).toString();
    ui->countryEmploymentLabel->setText(countryDate);


}
