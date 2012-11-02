
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commvisa.h"
#include "glwidget.h"
#include "datastorage.h"
#include "command.h"
#include "device.h"
#include <cstdlib>
#include <string.h>
#include <Qstring>
#include <QMessageBox>
#include <malloc.h>
#include <math.h>

#include <QThread>

CommVisa* objComm_Gpib = new CommVisa();
DataStorage *a;





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a = new DataStorage();

    Command *newCommand = new Command() ;

    SetStandardCommands();
    //QMessageBox msg;
    //msg.setText( newCommand->caption);
    //msg.exec();






    /*connect(this->ui->sbAltura, SIGNAL(valueChanged(int)),\
            this->objQGLWidget, SLOT(changeHeight(int)));*/

}

MainWindow::~MainWindow()
{
    /*free(*x);
    free(*y);
    free(*z);*/
    delete ui;
}

void MainWindow::on_actionDetect_Devices_triggered()
{
    ui->cbDispositivos->clear();
    ui->cbDispositivos->addItems(objComm_Gpib->find_instr());
    /*
    char* linha = objComm_Gpib->find_instr();
    char temp[100];
    short j=0;
    for (int i=0;linha[i]!='\0';i++){
        if (linha[i]!='\n'){
            temp[j]=linha[i];
            j++;
        }
        else{
            QString qtemp;
            qtemp.append(temp);
            j=0;
            temp[0]='\0';



            ui->cbDispositivos->addItem(qtemp);

        }
    }
    */
}

void MainWindow::SetStandardCommands(){
    //string a;
    ui->cbCmdPadroes->clear();
    for (int i=0;i< CommVisa::StandardCommands.size();i++){
        ui->cbCmdPadroes->addItem(CommVisa::StandardCommands[i]);
    }
    //return comm_gpib::StandardCommands;
}

void MainWindow::on_action_StandardCommands_triggered()
{
    SetStandardCommands();

}

void MainWindow::on_actionChoose_Command_triggered(int i)
{
    ui->txtSend->setText(ui->cbCmdPadroes->itemText(i));
}

void MainWindow::on_actionRead_triggered()
{
    QString qtemp;
    qtemp.append(objComm_Gpib->read());
    ui->txtRead->setText(qtemp);
}

void MainWindow::on_actionWrite_triggered()
{
    //QString qtemp;

    objComm_Gpib->write(ui->txtSend->toPlainText().toAscii().data());
    if (ui->txtSend->toPlainText().endsWith('?',Qt::CaseInsensitive)){
        this->on_actionRead_triggered();
    }
    //ui->txtRead->setText(qtemp);
}

void MainWindow::on_actionShowGraphics_triggered()
{
    objQGLWidget.setFixedSize(800,600);
    //objQGLWidget.xmin = -10;
    //objQGLWidget.xmax = +10;
    //objQGLWidget.ymin = -10;
    //objQGLWidget.ymax = +10;
    float ymax,ymin;
    QStringList strValuesList;
    QString item;
     objQGLWidget.qtd_i = 0;
    if (ui->txtRead->toPlainText().length()>0){
        strValuesList = ui->txtRead->toPlainText().split(",",QString::SkipEmptyParts);
        if (strValuesList.size()>0){
            objQGLWidget.f1 = (float *)malloc(strValuesList.size()*sizeof(float));
            item = strValuesList.at(0);
             objQGLWidget.f1[0] = item.toFloat();
             ymax = ymin = objQGLWidget.f1[0];
            for (int i=1;i<strValuesList.size();i++){
                item = strValuesList.at(i);
                 objQGLWidget.f1[i] = item.toFloat();
                 if (objQGLWidget.f1[i]>ymax) ymax=objQGLWidget.f1[i];
                 if (objQGLWidget.f1[i]<ymin) ymin=objQGLWidget.f1[i];
            }

            objQGLWidget.ymin = ymin;
            objQGLWidget.ymax = ymax;
            objQGLWidget.xmin = 0;
            objQGLWidget.xmax =  strValuesList.size()-1;
            objQGLWidget.inc = 1;
            objQGLWidget.qtd_i = strValuesList.size();
        }
        else{
            objQGLWidget.ymin = -100;
            objQGLWidget.ymax = 100;
            objQGLWidget.xmin = 0;
            objQGLWidget.xmax =  200;
            objQGLWidget.inc = 1;
            objQGLWidget.qtd_i = 0;
        }

    }

    objQGLWidget.f1 = (float*)malloc(1000*sizeof(float));
    objQGLWidget.qtd_i = 1000;
    objQGLWidget.xmin = 0;
    objQGLWidget.xmax = 1000;
    objQGLWidget.ymin = -300;
    objQGLWidget.ymax = 300;
    objQGLWidget.inc = 1;
    //float x_inc = 0;
    float g;
    for (int k=0;k<=999;k++){
        g = (float)(300.0f)*sin((float)2.0f*3.1415*k/200.0f) + 20.0*((float)rand()/RAND_MAX);
        objQGLWidget.f1[k] = g;


    }

    objQGLWidget.show();
}

void MainWindow::on_actionCmdPadroesChanged_triggered()
{
    ui->txtSend->clear();
    ui->txtSend->setText(ui->cbCmdPadroes->currentText());
}

QString transmissionHeader;

void MainWindow::on_actionDeviceSelected_triggered()
{
    int device = atoi(ui->cbDispositivos->currentText().mid(0,\
        ui->cbDispositivos->currentText().indexOf('-',0)).toAscii());
    objComm_Gpib->SetInterfaceAndDevice(objComm_Gpib->GetInterface(),device);


}

