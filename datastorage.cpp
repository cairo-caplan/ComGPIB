#include "datastorage.h"




typedef struct {
    int key;
    float value;
} Table1D;

typedef struct {
    int key;
    float value[2];
}Table2D;

typedef struct{
    int key;
    float value[2];
} Table3D;

typedef enum{
    D2,D3
}StorageType;

float *x;
float *y;
float *z;

//DataStorage::DataStorage(short dimension, int size)
DataStorage::DataStorage()
{
    if (!libraryDir.exists()){
            qWarning("O diretório %s não existe", libraryDir.absolutePath().toAscii().constData());
            return;
    }
    libraryDir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);

    ConfFileList = libraryDir.entryInfoList();

    this->ParseDeviceFiles();

    /*if (!libraryDir.exists()){
        qWarning("O diretório %s não existe", libraryDir.absolutePath().toAscii().constData());
        return;
    }

    libraryDir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);

    ConfFileList = libraryDir.entryInfoList();
    std::cout << "     Bytes Filename" << std::endl;
    QString filePath;
    for (int i = 0; i < ConfFileList.size(); i++) {
        filePath = ConfFileList.at(i).absoluteFilePath();
        if (filePath.endsWith(".conf",Qt::CaseInsensitive)){
            std::cout << qPrintable(QString("%1").arg(filePath)) << std::endl;*/
            //DataStorage::ParseFile(filePath);
            /*
        }
    }*/



}

enum ParsingPartType{CommandPart,CaptionPart,ArgPart,QueryPart,ChildrenCommandsPart,VariantPart};
 //Função que decifra um arquivo de configuracao de um instrumento





bool DataStorage::ParseFile(QString filepath){
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
     QString strCommand = "";
     bool valueMode = false;
     bool forcedValueMode = false;
     bool parsingCommandName = true;
     short BarCount = 0;
     short keyCounter = 0;
     short OpenBracketCol = 0;
     int OpenBracketLine = 0;
     short CloseBracketCol = 0;
     int CloseBracketLine = 0;


     ParsingPartType ParsingType=CommandPart;
     QString strTemp = "";
     Command* CurrCommand = new Command();
     char character;

     //varre todas as linhas
     for (int i=0; i<lines.count() ; i++){
         //varre todos os caracteres da linha
         for (int j=0;j<lines.at(i).length();j++){
             if (keyCounter<0){
                 j = lines.at(i).length()+1;
                 i = lines.count()+1;
             }
             else{
                 character = lines.at(i).at(j).toAscii();
                 switch(character){
                     case ':':
                         if (!forcedValueMode){
                             if  (ParsingType==CommandPart){
                                    CurrCommand->Name = strTemp;
                                    strTemp.clear();
        //                            QMessageBox msg;
        //                            msg.setText(this->Name);
        //                            msg.exec();
                             }
                             else{
                                 valueMode = true;
                             }
                         } else strTemp.append(character);

                         break;
                     case '"':
                        forcedValueMode = !forcedValueMode;
                        if (forcedValueMode) valueMode=true;
                        break;
                     case ',':
                         if (!forcedValueMode){
                             valueMode = false;
                         } else strTemp.append(character);
                        break;
                     case '{':
                         if (!forcedValueMode){
                             keyCounter+=1;
                         } else strTemp.append(character);
                        break;
                     case '}':
                         if (!forcedValueMode){
                             keyCounter-=1;
                         } else strTemp.append(character);
                        break;
                     case '[':
                        if (!forcedValueMode){
                            if (ParsingType==ChildrenCommandsPart){
                                OpenBracketCol = j;
                                OpenBracketLine = i;
                            }

                        } else strTemp.append(character);
                    case ']':
                        if (!forcedValueMode){
                            if (ParsingType==ChildrenCommandsPart){
                                CloseBracketCol = j;
                                CloseBracketLine = i;
                            }

                        } else strTemp.append(character);

                    default:
                        strTemp.append(character);
                        break;
                 }
             }
         }

         printf("\n%s",lines.at(i).toLocal8Bit().constData());
     }
    return true;

 }

bool DataStorage::ParseDeviceFiles(){
    //QFile CurrFile;
    //para cada arquivo
    QString firstLine;
    QStringList firstLineSplitted;
    for (int i=0; i<ConfFileList.size(); i++){
        QFile CurrFile(ConfFileList.at(i).absoluteFilePath());
        //tente abrir o arquivo, caso falhe, retorne falso
        if (!CurrFile.open(QIODevice::ReadOnly | QIODevice::Text))
                 return false;
        QTextStream in(&CurrFile);
        //Leia a primeira linha, por estar conter informação de identificação de dispositivo ou
        //série que este arquivo se trata
        firstLine = in.readLine();
        firstLineSplitted = firstLine.split(",",QString::KeepEmptyParts);
        if (firstLineSplitted.size() >1){
            if (!DataStorage::DeviceList.isEmpty()){
                for (int j=0;j<DeviceList.size();j++){
                    if (QString::compare(DataStorage::DeviceList.at(j).manufacturer, \
                                         firstLineSplitted.at(0), \
                                         Qt::CaseInsensitive)==0){


                    }
                }
            }
        }


    }

}
