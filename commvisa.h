#ifndef COMM_H
#define COMM_H
#include <QString>
#include <QStringList>
#include <QThread>



class CommVisa : public QThread
{
public:
    CommVisa();
    //char* find_instr();
    QStringList find_instr();
    static QStringList StandardCommands;
    bool write(char *command);
    char* read();
    ~CommVisa();
    bool SetInterfaceAndDevice(short n,short d);
    short GetInterface();
    short GetDevice();
private:
    short interface;
    short device;


};

#endif // COMM_H
