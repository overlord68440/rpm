#include "serv.h"
#include <unistd.h>

#include <iostream>
serv::serv(QObject *parent) : QTcpServer(parent)
{
    createCommunicationFile() ;

    QString s1 = "--input-ipc-server=" ;
    QString s = FILE_TEMP_NAME ;
    s = s1 + s ;
    arguments << "--idle" << s  ;

    runMPV();
    connectToMPV() ;

        QJsonArray toSend ;
        toSend.append( "loadfile");
        toSend.append("/home/overlord/Bureau/monster.mp3");
        QJsonObject jsonObject ;
        jsonObject["command"]=toSend;

        QByteArray bytes = QJsonDocument(jsonObject).toJson(QJsonDocument::Compact)+"\n";
        sendToMPV(bytes);

        QThread::sleep(1) ;
        QJsonArray toSend2 ;
        toSend2.append( "cycle-values");
        toSend2.append("loop-file");
        toSend2.append("inf");
        QJsonObject jsonObject2 ;
        jsonObject2["command"]=toSend2;
        bytes = QJsonDocument(jsonObject2).toJson(QJsonDocument::Compact)+"\n";
        sendToMPV(bytes);

        QThread::sleep(2) ;
        QJsonArray toSend3 ;
        toSend3.append( "stop");
//        toSend3.append("volume");

  //      toSend3.append("show-progress");
        QJsonObject jsonObject3 ;
        jsonObject3["command"]=toSend3;

        bytes = QJsonDocument(jsonObject3).toJson(QJsonDocument::Compact)+"\n";
        sendToMPV(bytes);
        sleep (5) ;

}

serv::~serv()
{
    myProcess->kill();
    myProcess->~QProcess() ;
    mpv->disconnect();
    mpv->~QLocalSocket() ;
    QFile::remove(FILE_TEMP_NAME) ;
}

void serv::start()
{
    if(!this->listen(QHostAddress::Any, 12000))
        qDebug() << "Server could not start!";
    else
        qDebug() << "Server started!";

    QObject:: connect(this, SIGNAL(newConnection()), this, SLOT(connection()));
}

void serv::createCommunicationFile()
{
    tempFile.setFileName(FILE_TEMP_NAME);
    if(!tempFile.open(QIODevice::ReadWrite))
        qDebug() << "files issues" ;
    tempFile.close();

}

void serv::runMPV()
{
    myProcess= new QProcess(this) ;

    if(myProcess->startDetached("mpv", arguments))
            qDebug() <<"process started" ;
    else
            qDebug() << "failure" ;
    QThread::sleep(2) ;    //tempo pour attendre que mpv etablisse la connexion
}

void serv::connectToMPV()
{
    QString s = path +'/'+ FILE_TEMP_NAME ;
    qDebug() << s ;
    mpv= new QLocalSocket(this) ;
    mpv->connectToServer(s);

    if (mpv->waitForConnected())
        qDebug() << "connected to mpv";
    else
    {
        qDebug() <<" connection to mpv failed" ;
        mpv->error();
    }
}

void serv::sendToMPV(QByteArray bytes)
{
    if (mpv!=NULL)
    {
      mpv->write(bytes.data(), bytes.length());
      mpv->flush();
    }
}

void serv::connection()
{
    /*QFutureWatcher<void> watcher;
    connect(&watcher, SIGNAL(finished()), this, SLOT(handleFinished()));
    qDebug() << "lancement thread";
    QFuture<void> future = QtConcurrent::run(this,&serv::runClientThread);
    watcher.setFuture(future);
    QFutureSynchronizer<void> sync ;
    sync.addFuture(future);*/

    clientSock *c = new clientSock(this->nextPendingConnection());
    clientList << c ;
    //c->writeSock("Hello client\r\n");

}




/*
void serv::runClientThread()
{
    clientSock *client=new clientSock(this->nextPendingConnection()) ;
    connect(client->csock, SIGNAL(connected()), client, SLOT(connected()));
    connect(client->csock, SIGNAL(disconnected()), client, SLOT(disconnected()));
    connect(client->csock, SIGNAL(readyRead()), client, SLOT(readSock()));
   // client->writeSock("bonjour bonjour");

}

*/



