#include "getterofsocketdata.h"
#include <QDataStream>
#include <QByteArray>
//#include "../Common/packetsandstructures.h"
#include <stdio.h>
#include <string.h>
#include <QTime>
#include <QProcess>
#include <QMutex>

int32_t arrGD[2][NUMBEROFPOINTS];
extern QMutex mutexSpec;
extern QMutex mutexInterf;

bool isSubstanceFromList(char No);

getterOfSocketData::getterOfSocketData(QObject *parent) : QObject(parent),ipAdr("192.168.1.1"),portNo(40230)
{

}

void getterOfSocketData::setRequest(char *in, int size)
{

}

void getterOfSocketData::sendRequest()
{


}

bool isSubstanceFromList(char No);

//float Corr[_CHAN_NUM_];
void getterOfSocketData::processAnswer()
{
    int bA = socket->bytesAvailable();
    qDebug() << __FUNCTION__;
    int numOfPointsWaiting = NUMBEROFPOINTS;
    if (bA<numOfPointsWaiting*sizeof (uint32_t)*2)
    {
        return;
    }
    int readed = 0;
    char * uk = (char*)arrGD;
//    QByteArray byteArr(numOfPointsWaiting*sizeof (uint32_t)*2);
//    byteArr = socket->read(numOfPointsWaiting*sizeof (uint32_t)*2);
    mutexInterf.lock();
    //memcpy
    readed = socket->read(uk,numOfPointsWaiting*sizeof (uint32_t)*2);
//    memcpy(uk,byteArr.data(),numOfPointsWaiting*sizeof (uint32_t)*2);
    mutexInterf.unlock();
    QByteArray ba(uk,numOfPointsWaiting*sizeof (uint32_t)*2);
    emit giveInterf();
    emit giveInterf(ba);
    qDebug() << __FUNCTION__ << " readed " << readed << " bytes!\n";
//    socket->readAll();


}



