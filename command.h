#ifndef COMMAND_H
#define COMMAND_H

#include <QString>
#include <QList>


bool ParseFile(QString filepath);

enum QueryMode{
    Yes,No,YesOnly
};

enum ArgTypeCode_t{
    ENUMERATION,INTEGER,REAL,STRING
};

typedef struct {
    ArgTypeCode_t ArgTypeCode;
    QStringList* AllowedEnumValues;
}Arg_t;


class Command {
public:

    QString Name;
    QString caption;
    QString Arg;
    QueryMode isQuery;
    QList<Command> *ChildCommands;
    Command *Parent;

    Command();

    void FullCommand();
private:
    bool isEndNode;
    bool isRootNode;
    bool ParseFile(QString filepath);
    Command ScriptInterpreter(QString text);



};


#endif // COMMAND_H
