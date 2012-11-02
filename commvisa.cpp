#include "commvisa.h"
#include <visa.h>
//#include <iostream>

#include <stdio.h>
#include <QString>
#include <QStringList>
#include <QThread>

ViSession defaultRM, vi;
  //char buf [256] = {0};
char buf [2000] = {0};
char instrument_address[30];

bool CommVisa::SetInterfaceAndDevice(short n,short d){

    if (vi!=NULL){
        viClose (vi);
        viClose (defaultRM);
    }
    if ((n==NULL)||(n!=interface)||(d!=device)){
        //d = 1;
        viOpenDefaultRM (&defaultRM);
        sprintf(instrument_address,"GPIB%d::%d::INSTR",n,d);
        viOpen (defaultRM,instrument_address, VI_NULL,VI_NULL, &vi);
        if (vi==NULL) return false;
        CommVisa::interface = n;
        CommVisa::device = d;

    }
    return true;
}

short CommVisa::GetInterface(){
    return interface;
}

short CommVisa::GetDevice(){
    return device;
}



 QStringList CommVisa::StandardCommands  = (QStringList() << "*IDN?" << "*RST"<<"*TST?"<<"*OPC" \
                              <<"*OPC?"<<"WAI"<<"*CLS"<<"*ESE"<<"*SRE?");



CommVisa::~CommVisa(){
    viClose (vi);
    viClose (defaultRM);
    buf[0]='\0';
}

CommVisa::CommVisa()
{

    CommVisa::interface=0;
      /* Open session to GPIB device at address 22 */
      viOpenDefaultRM (&defaultRM);
      sprintf(instrument_address,"GPIB%d::%d::INSTR",interface,0);
      viOpen (defaultRM,instrument_address, VI_NULL,VI_NULL, &vi);

      /* Initialize device */
      //viPrintf (vi, "*RST\n");

      /* Send an *IDN? string to the device */
     // viPrintf (vi, "*IDN?\n");

      /* Read results */
      //viScanf (vi, "%t", &buf);

      /* Print results */
      //printf ("Instrument identification string: %s\n", buf);
      //cout << "Instrument identification string: " << buf << "\n";

      /* Close session */

}

QStringList CommVisa::find_instr(){
    //char response[1000];
    QStringList response;

    char instrument_address[30];
    /* Open session to GPIB device at address 22 */
    /////////////////////////
    int i;
    char aux[262];
    for (i=0;i<32;i++){

        viOpenDefaultRM (&defaultRM);
        sprintf(instrument_address,"GPIB%d::%d::INSTR",interface,i);
        viOpen (defaultRM, instrument_address, VI_NULL,VI_NULL, &vi);
        /* Send an *IDN? string to the device */
        viPrintf (vi, "*IDN?\n");
        /* Read results */
        viScanf (vi, "%t", &buf);
        /* Print results */
        //sprintf (response,"Instrument identification string: %d %s\n",i, buf);
        if (strlen(buf)>0){
            sprintf(aux,"%d - %s",i,buf);
            response.append(QString::fromAscii(aux));
            printf("%s \n",response.last().toAscii().data());
        }

        /* Close session */

        //viClose (vi);
        //viClose (defaultRM);

        buf[0]='\0';

    }
    return response;

}

bool CommVisa::write(char* command){
    //viOpenDefaultRM (&defaultRM);
    //sprintf_s(instrument_address,"GPIB0::1::INSTR",i);
    //viOpen (defaultRM, instrument_address, VI_NULL,VI_NULL, &vi);

     viPrintf (vi, "%s\n",command);
     return true;
}

char* CommVisa::read(){

    //viOpenDefaultRM (&defaultRM);
    //sprintf_s(instrument_address,"GPIB0::1::INSTR",i);
    //viOpen (defaultRM, instrument_address, VI_NULL,VI_NULL, &vi);
     viScanf (vi, "%t", &buf);
     return buf;
}

char* checkErrExit()

{
    /*if(ibsta & ERR) // an error occurred

    {

    switch (iberr) {

        case EDVR:            // ibcntl contains a sub-error code

            printf("System error %d\n",ibcntl);

            break;

        case ECIC:

            printf("Not Controller in Charge \n");

            break;

        case ENOL:

            printf("No Listeners \n");

            break;

        case EADR:

            printf("GPIB interface not addressed correctly \n");

            break;

        case EARG:

            printf("Invalid argument to function call \n ");

            break;

        case ESAC:

            printf("GPIB interface not System Controller as required \n ");

            break;

        case EABO:

            printf("I/O operation aborted (timeout) \n");

            break;

        case ENEB:

            printf("Nonexistent GPIB interface \n");

            break;

        case EDMA:

            printf("DMA error \n");

            break;

        case EOIP:

            printf("Asynchronous I/O in progress \n ");

            break;

        case ECAP:

            printf("No capability for operation \n");

            break;

        case EFSO:

            printf("File system error \n");

            break;

        case EBUS:

            printf("GPIB bus error \n");

            break;

        case ESRQ:

            printf("SRQ stuck in ON position \n");

            break;

        case ETAB:

            printf("Table problem \n");

            break;

        case ELCK:

            printf("Interface is locked \n");

            break;

        case EARM:

            printf("ibnotify callback failed to rearm \n");

            break;

        case EHDL:

            printf("Input handle is invalid \n ");

            break;

        case EWIP:

            printf("Wait in progress on specified input handle \n");

            break;

        case ERST:

            printf("The event notification was cancelled due to a reset of the interface \n");

            break;

        case EPWR:

            printf("The interface lost power \n");

            break;

        default:

            printf("Unexpected error \n");

            break;

    }

    exit (1);// exit the program in case of any error

    }

*/

    return 0;

}


