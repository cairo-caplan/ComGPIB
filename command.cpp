
#include "command.h"
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>



    Command::Command(){
        this->caption="*IDN?";
        this->isEndNode=true;
        this->isRootNode=true;
        this->isQuery = No;
        ParseFile("C:/Users/Cairo/Documents/Projetos/Projeto_GPIB_Qt_2/debug/lol.txt");
    }


 void Command::FullCommand(){
        if (this->isEndNode){
            QString FullCommand;
            while(true){

            }
        }

    }


enum ParsingPartType{CommandPart,CaptionPart,ArgPart,QueryPart,ChildPart,VariantPart};
 //Função que decifra um arquivo de configuracao de um instrumento
bool Command::ParseFile(QString filepath){
     QFile file(filepath);
     //verifica se o arquivo existe e eh legivel
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
              return false;

     //le todo o arquivo como um fluxo de texto, atribuindo cada linha na lista lines
     //Esta etapa só trata da leitura do arquivo para poder travar este arquivo no mínimo de tempo possível
     QStringList lines;
     QTextStream in(&file);
     while (!in.atEnd()) {
         lines += in.readLine();
     }
     file.close();

     //Divide cada campo do texto
     QString strCommand="";
     bool valueMode = false;
     bool parsingCommandName=true;

     ParsingPartType ParsingType=CommandPart;
     QString strTemp = "";
     for (int i=0; i<lines.count() ; i++){
         for (int j=0;j<lines.at(i).length();j++){
             char character = lines.at(i).at(j).toAscii();
             switch(character){
                 case ':':
                     switch (ParsingType){
                        case CommandPart:
                            this->Name = strTemp;
                            strTemp.clear();
//                            QMessageBox msg;
//                            msg.setText(this->Name);
//                            msg.exec();
                            break;
                     }
                     break;
                 case '"':
                    valueMode = !valueMode;
                    break;
                 case ',':
                     if (!valueMode){


                     }
                    break;
                 case '{':
                    break;
                 case '}':
                    break;
                default:
                    strTemp.append(character);
                    break;
             }
         }

         printf("\n%s",lines.at(i).toLocal8Bit().constData());
     }
    return true;

 }





