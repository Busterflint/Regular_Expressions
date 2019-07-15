#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "registrationchecker.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listView->setModel(&regNumbers);

    connect(ui->buttonAdd, SIGNAL(clicked()), this, SLOT(addRecord()));
    connect(ui->buttonDelete, SIGNAL(clicked()), this, SLOT(deleteRecord()));
    connect(ui->number, SIGNAL(returnPressed()),this, SLOT(addRecord()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// slot to handle the add button
void MainWindow::addRecord()
{
    QString temp = QString(ui->number->text()).toUpper();
    RegistrationChecker rc;
    int begin;
    if (rc.validate(temp, begin)==QValidator::Acceptable)
    {
        regNumbers.add(temp);
        ui->number->clear();
    }
    else
        QMessageBox::warning(this, "Error", "Not an acceptable registration number", QMessageBox::Ok);
    ui->number->setFocus();
}

// slot to handle the delete button
void MainWindow::deleteRecord()
{
    if (QMessageBox::warning(this, "Delete record", "Are you sure you want to delete?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
    {
        QModelIndex index = ui->listView->currentIndex();
        if (!index.isValid())
            return;
        regNumbers.removeRows(index.row(), 1, index);
    }
}
