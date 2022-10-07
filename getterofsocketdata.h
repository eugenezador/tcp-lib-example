#ifndef GETTEROFSOCKETDATA_H
#define GETTEROFSOCKETDATA_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include "constants.h"

class getterOfSocketData : public QObject
{
    Q_OBJECT

private:
    //QTcpSocket * socket;
    QTimer * timerRepeatConnection;
    QTimer *timerRepeatRequest;
    int timeBetweenRequest;
    bool connectionDone,needToSendSbros,bFirstDetection;
    QString ipAdr;
    int portNo;
public:
    explicit getterOfSocketData(QObject *parent = nullptr);
    QTcpSocket * socket;
signals:
    void connectionToOMBDone();
    void sendReadyStateOrError(int);
    void cloudCorrReady(float*,int);
    void sendRecogString(QString,int);
    void sendReadyState();
    void setAKB(int);
    void setContrast(float);
    void SendCode(unsigned char);
    void sendCorrectTime(QString);

    void sendStateAndDetection(unsigned char,unsigned char,unsigned char,unsigned char,int,signed char);

    void giveInterf();
    void giveInterf(const QByteArray);


public slots:
    void setIP(QString s)
    {
        ipAdr = s;
    }
    void initModule()
    {
        printf("%s\n",__FUNCTION__);
        timerRepeatRequest = new QTimer();
        timerRepeatConnection = new QTimer();
        socket = new QTcpSocket();
        connectionDone = false;
        connect(socket,SIGNAL(connected()),
                this,SLOT(slotConnected()));
        connect(socket,SIGNAL(disconnected()),
                this,SLOT(slotDisonnected()));
        connect(socket,SIGNAL(hostFound()),
                this,SLOT(slotHostFound()));
//        connect(timerRepeatRequest,SIGNAL(timeout()),
//                this,SLOT(sendRequest()));
        connect(socket,SIGNAL(readyRead()),
                this,SLOT(processAnswer()));
//        connect(timerRepeatConnection,SIGNAL(timeout()),
//                this,SLOT(initConnection()));
//        timerRepeatConnection->start(5000);
    }
    void initConnection()
    {
        qDebug() << __FUNCTION__  << "ip "<<ipAdr<<" port "<<portNo;
        if (!connectionDone)
        {
            socket->connectToHost(ipAdr,portNo);
            if (socket->waitForConnected(3000) == -1) qDebug() << "Cannot connect to server !!!\n";
        }

    }
    void slotHostFound()
    {
        printf("%s\n",__FUNCTION__);
    }
    void slotConnected()
    {
        printf("CONECTED TO OMB!\n");
        connectionDone = true;
        timerRepeatRequest->start(timeBetweenRequest);
        emit connectionToOMBDone();
    }

    void slotDisonnected()
    {
        printf("DISCONECTED FROM OMB!\n");
        connectionDone = false;
        timerRepeatRequest->stop();
    }
    void setRequest(char * in,int size);
    void sendRequest();
    void processAnswer();

};

#endif // GETTEROFSOCKETDATA_H
