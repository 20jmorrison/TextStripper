#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stripText.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    StripText Stripper;

    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void import_file();
    void export_file();
    void convert();
};
#endif // MAINWINDOW_H
