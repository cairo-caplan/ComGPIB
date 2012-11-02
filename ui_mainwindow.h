/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 14. Oct 13:36:27 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDetect_Devices;
    QAction *actionRead;
    QAction *actionWrite;
    QAction *action_StandardCommands;
    QAction *actionShowGraphics;
    QAction *actionCmdPadroesChanged;
    QAction *actionDeviceSelected;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QComboBox *cbCmdPadroes;
    QTabWidget *tabWidget;
    QWidget *pagComandos;
    QTreeWidget *tvwComandos;
    QComboBox *cbDispositivos;
    QPushButton *btnDetectar;
    QWidget *tab;
    QComboBox *cbPortaComm;
    QLabel *lblPorta;
    QLabel *lblLargura_2;
    QSpinBox *sbLargura;
    QSpinBox *sbAltura;
    QLabel *lblLargura;
    QGroupBox *gbLerEnviar;
    QTextEdit *txtRead;
    QPushButton *btnLer;
    QTextEdit *txtSend;
    QPushButton *btnEnviar;
    QGraphicsView *graphicsView;
    QPushButton *btnShowGraphics;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(755, 462);
        MainWindow->setAutoFillBackground(false);
        actionDetect_Devices = new QAction(MainWindow);
        actionDetect_Devices->setObjectName(QString::fromUtf8("actionDetect_Devices"));
        actionRead = new QAction(MainWindow);
        actionRead->setObjectName(QString::fromUtf8("actionRead"));
        actionWrite = new QAction(MainWindow);
        actionWrite->setObjectName(QString::fromUtf8("actionWrite"));
        action_StandardCommands = new QAction(MainWindow);
        action_StandardCommands->setObjectName(QString::fromUtf8("action_StandardCommands"));
        actionShowGraphics = new QAction(MainWindow);
        actionShowGraphics->setObjectName(QString::fromUtf8("actionShowGraphics"));
        actionCmdPadroesChanged = new QAction(MainWindow);
        actionCmdPadroesChanged->setObjectName(QString::fromUtf8("actionCmdPadroesChanged"));
        actionDeviceSelected = new QAction(MainWindow);
        actionDeviceSelected->setObjectName(QString::fromUtf8("actionDeviceSelected"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(650, 370, 75, 23));
        cbCmdPadroes = new QComboBox(centralWidget);
        cbCmdPadroes->setObjectName(QString::fromUtf8("cbCmdPadroes"));
        cbCmdPadroes->setGeometry(QRect(30, 290, 151, 22));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbCmdPadroes->sizePolicy().hasHeightForWidth());
        cbCmdPadroes->setSizePolicy(sizePolicy);
        cbCmdPadroes->setMinimumSize(QSize(0, 0));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 581, 271));
        tabWidget->setTabPosition(QTabWidget::North);
        pagComandos = new QWidget();
        pagComandos->setObjectName(QString::fromUtf8("pagComandos"));
        tvwComandos = new QTreeWidget(pagComandos);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        tvwComandos->setHeaderItem(__qtreewidgetitem);
        tvwComandos->setObjectName(QString::fromUtf8("tvwComandos"));
        tvwComandos->setGeometry(QRect(20, 71, 541, 171));
        cbDispositivos = new QComboBox(pagComandos);
        cbDispositivos->setObjectName(QString::fromUtf8("cbDispositivos"));
        cbDispositivos->setGeometry(QRect(20, 40, 541, 27));
        btnDetectar = new QPushButton(pagComandos);
        btnDetectar->setObjectName(QString::fromUtf8("btnDetectar"));
        btnDetectar->setGeometry(QRect(20, 6, 541, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8("img/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDetectar->setIcon(icon);
        btnDetectar->setIconSize(QSize(32, 32));
        tabWidget->addTab(pagComandos, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        cbPortaComm = new QComboBox(tab);
        cbPortaComm->setObjectName(QString::fromUtf8("cbPortaComm"));
        cbPortaComm->setGeometry(QRect(10, 40, 101, 22));
        lblPorta = new QLabel(tab);
        lblPorta->setObjectName(QString::fromUtf8("lblPorta"));
        lblPorta->setGeometry(QRect(10, 10, 121, 31));
        lblLargura_2 = new QLabel(tab);
        lblLargura_2->setObjectName(QString::fromUtf8("lblLargura_2"));
        lblLargura_2->setGeometry(QRect(10, 110, 81, 16));
        sbLargura = new QSpinBox(tab);
        sbLargura->setObjectName(QString::fromUtf8("sbLargura"));
        sbLargura->setGeometry(QRect(100, 80, 42, 22));
        sbLargura->setMinimum(10);
        sbLargura->setMaximum(1280);
        sbLargura->setValue(640);
        sbAltura = new QSpinBox(tab);
        sbAltura->setObjectName(QString::fromUtf8("sbAltura"));
        sbAltura->setGeometry(QRect(100, 110, 42, 22));
        sbAltura->setMinimum(10);
        sbAltura->setMaximum(1024);
        sbAltura->setValue(480);
        lblLargura = new QLabel(tab);
        lblLargura->setObjectName(QString::fromUtf8("lblLargura"));
        lblLargura->setGeometry(QRect(10, 80, 81, 16));
        tabWidget->addTab(tab, QString());
        gbLerEnviar = new QGroupBox(centralWidget);
        gbLerEnviar->setObjectName(QString::fromUtf8("gbLerEnviar"));
        gbLerEnviar->setGeometry(QRect(10, 320, 571, 81));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gbLerEnviar->sizePolicy().hasHeightForWidth());
        gbLerEnviar->setSizePolicy(sizePolicy1);
        gbLerEnviar->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        txtRead = new QTextEdit(gbLerEnviar);
        txtRead->setObjectName(QString::fromUtf8("txtRead"));
        txtRead->setGeometry(QRect(10, 40, 451, 31));
        txtRead->setReadOnly(true);
        btnLer = new QPushButton(gbLerEnviar);
        btnLer->setObjectName(QString::fromUtf8("btnLer"));
        btnLer->setGeometry(QRect(470, 40, 86, 27));
        txtSend = new QTextEdit(gbLerEnviar);
        txtSend->setObjectName(QString::fromUtf8("txtSend"));
        txtSend->setGeometry(QRect(10, 10, 451, 21));
        btnEnviar = new QPushButton(gbLerEnviar);
        btnEnviar->setObjectName(QString::fromUtf8("btnEnviar"));
        btnEnviar->setGeometry(QRect(470, 10, 86, 27));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(670, 10, 71, 271));
        btnShowGraphics = new QPushButton(centralWidget);
        btnShowGraphics->setObjectName(QString::fromUtf8("btnShowGraphics"));
        btnShowGraphics->setGeometry(QRect(630, 340, 91, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 755, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(btnDetectar, SIGNAL(clicked()), actionDetect_Devices, SLOT(trigger()));
        QObject::connect(btnEnviar, SIGNAL(clicked()), actionWrite, SLOT(trigger()));
        QObject::connect(btnLer, SIGNAL(clicked()), actionRead, SLOT(trigger()));
        QObject::connect(btnShowGraphics, SIGNAL(clicked()), actionShowGraphics, SLOT(trigger()));
        QObject::connect(cbCmdPadroes, SIGNAL(currentIndexChanged(QString)), actionCmdPadroesChanged, SLOT(trigger()));
        QObject::connect(cbDispositivos, SIGNAL(currentIndexChanged(QString)), actionDeviceSelected, SLOT(trigger()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionDetect_Devices->setText(QApplication::translate("MainWindow", "Detect Devices", 0, QApplication::UnicodeUTF8));
        actionRead->setText(QApplication::translate("MainWindow", "Read", 0, QApplication::UnicodeUTF8));
        actionWrite->setText(QApplication::translate("MainWindow", "Write", 0, QApplication::UnicodeUTF8));
        action_StandardCommands->setText(QApplication::translate("MainWindow", " Standard Commands", 0, QApplication::UnicodeUTF8));
        actionShowGraphics->setText(QApplication::translate("MainWindow", "ShowGraphics", 0, QApplication::UnicodeUTF8));
        actionCmdPadroesChanged->setText(QApplication::translate("MainWindow", "CmdPadroes", 0, QApplication::UnicodeUTF8));
        actionDeviceSelected->setText(QApplication::translate("MainWindow", "DeviceSelected", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        cbCmdPadroes->clear();
        cbCmdPadroes->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "*IDN?", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_ACCESSIBILITY
        pagComandos->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        btnDetectar->setText(QApplication::translate("MainWindow", "&Detectar dispositivos", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(pagComandos), QApplication::translate("MainWindow", "&Comandos", 0, QApplication::UnicodeUTF8));
        cbPortaComm->clear();
        cbPortaComm->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "GPIB0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "GPIB1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "GPIB2", 0, QApplication::UnicodeUTF8)
        );
        lblPorta->setText(QApplication::translate("MainWindow", "Porta de comunica\303\247\303\243o", 0, QApplication::UnicodeUTF8));
        lblLargura_2->setText(QApplication::translate("MainWindow", "Altura da Tela:", 0, QApplication::UnicodeUTF8));
        lblLargura->setText(QApplication::translate("MainWindow", "Largura da Tela:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "&Configura\303\247\303\265es", 0, QApplication::UnicodeUTF8));
        gbLerEnviar->setTitle(QString());
        btnLer->setText(QApplication::translate("MainWindow", "&Ler", 0, QApplication::UnicodeUTF8));
        btnEnviar->setText(QApplication::translate("MainWindow", "&Enviar", 0, QApplication::UnicodeUTF8));
        btnShowGraphics->setText(QApplication::translate("MainWindow", "Exibe Gr\303\241fico", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
