#include "config.h"

config::config()
{
}

config::getAbsDeviceDir(){
    QString return_value;
    return_value << QCoreApplication::applicationDirPath();
    return_value << config::device_conf_rel_dir;
    return return_value;
}

