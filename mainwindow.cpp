#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"
#include "stripText.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->importFile, SIGNAL(released()), this, SLOT(import_file()));
    connect(ui->exportFile, SIGNAL(released()), this, SLOT(export_file()));
    connect(ui->convertButton, SIGNAL(released()), this, SLOT(convert()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::import_file()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Select an image"),
                                                ".", tr("txt files (*.txt)\n"));
    ui->importLocation->setPlainText(file);
    Stripper.setInFile(file);

}

void MainWindow::export_file()
{
    QString dir = QFileDialog::getOpenFileName(this, tr("Select an image"),
                                                ".", tr("txt files (*.txt)\n"));
    ui->exportLocation->setPlainText(dir);
    Stripper.setOutFile(dir);
}

void MainWindow::convert()
{
    Stripper.commence();
}



