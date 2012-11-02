#ifndef CONFIG_H
#define CONFIG_H
#include <QString>
#include <QCoreApplication>
#include <QDir>

class config
{
public:
    config();
    static QString getAbsDeviceDir();
private:
    static QString device_conf_rel_dir = "/lib";

};

#endif // CONFIG_H
