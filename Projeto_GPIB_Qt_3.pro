#-------------------------------------------------8.lib
#
# Project created by QtCreator 2012-04-25T22:41:57
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = Projeto_GPIB_Qt_2
TEMPLATE = app

    #INCLUDEPATH += "C:\Program Files\IVI Foundation\VISA\Win64\Include"
    #LIBS += "C:\Program Files\IVI Foundation\VISA\Win64\Bin\*.dll"
#"C:\Program Files\IVI Foundation\VISA\Win64\Lib_x64\msc\visa32.lib"



win32{
    #INCLUDEPATH += "C:\Program Files\IVI Foundation\VISA\WinNT\include"
    #LIBS += "C:\Program Files\IVI Foundation\VISA\WinNT\lib\msc\visa32.lib"
    #INCLUDEPATH += "C:\Program Files\IVI Foundation\VISA\WinNT\include"
    #LIBS += "C:\Program Files\IVI Foundation\VISA\WinNT\lib\msc\visa32.lib"
    INCLUDEPATH += "C:\Program Files (x86)\IVI Foundation\VISA\WinNT\include"
    LIBS += "C:\Program Files (x86)\IVI Foundation\VISA\WinNT\lib\msc\visa32.lib"
}

win64{



    #INCLUDEPATH += "C:/Program Files/IVI Foundation/VISA/Win64/agvisa/include/"
    #LIBS += "C:/Program Files/IVI Foundation/VISA/Win64/agvisa/lib/msc/*.lib"
    #LIBS += -lvisa
}

#win32 {
#    #/* If you compile with QtCreator/gcc: */
#    win32-g++:LIBS += -L"$$_PRO_FILE_PWD_/libs/"
#    win32-g++:LIBS += -lyaml-cpp

#    #/* IF you compile with MSVC:
#    #win32-msvc:LIBS += /path/to/your/libMyLib.lib*/
#}


#macx {
#    LIBS += -L"$$_PRO_FILE_PWD_/libs/"
#    LIBS += -lyaml-cpp-mac
#}

linux{
    LIBS+= lgpib
}


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    datastorage.cpp \
    commvisa.cpp \
    device.cpp \
    command.cpp \
    scriptmanager.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    datastorage.h \
    commvisa.h \
    device.h \
    command.h \
    configuration.h \
    scriptmanager.h

FORMS    += \
    mainwindow.ui
