#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commvisa.h"
#include "glwidget.h"
#include <cstdlib>
#include <string.h>
#include <Qstring>

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    GLWidget objQGLWidget;


private:
    Ui::MainWindow *ui;
    void SetStandardCommands();


private slots:
    void on_actionDetect_Devices_triggered();
    void on_action_StandardCommands_triggered();
    void on_actionChoose_Command_triggered(int i);
    void on_actionRead_triggered();
    void on_actionWrite_triggered();
    void on_actionShowGraphics_triggered();
    void on_actionCmdPadroesChanged_triggered();
    void on_actionDeviceSelected_triggered();
};

#endif // MAINWINDOW_H



