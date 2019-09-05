#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileDialog>
#include<QFileInfo>
#include<QDir>
#include<QMessageBox>
#include <QDateTime>
#include <QTextStream>
#include<QString>
#include<QStringList>
#include<QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void getFileInfoSlot();


};

#endif // MAINWINDOW_H
