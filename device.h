#ifndef DEVICE_H
#define DEVICE_H
#include <QList>
#include <QObject>
#include <QHash>
#include <command.h>


class Device
{
public:
    Device();
    QString manufacturer;
    QHash <QString, QString>device_series;

    QList<Command> Commands;


};

#endif // DEVICE_H
