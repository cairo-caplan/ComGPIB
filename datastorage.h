#ifndef DATASTORAGE_H
#define DATASTORAGE_H
#include  <malloc.h>
#include <stdio.h>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QHash>
#include <QMutableHashIterator>
#include "command.h"
#include "configuration.h"
#include <iostream>
#include <stdlib.h>
#include <device.h>

class DataStorage
{
public:
    DataStorage();
    bool ParseFile(QString filepath);
    QList <Device>DeviceList;
private:
        QFileInfoList ConfFileList;
        bool ParseDeviceFiles();

};

#endif // DATASTORAGE_H
