#include "clientsock.h"

clientSock::clientSock(QTcpSocket *sock)
{
    csock=sock ;
    qDebug() << "SOCKET CREATED";
    connect(csock, SIGNAL(connected()), this, SLOT(connected()));
    connect(csock, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(csock, SIGNAL(readyRead()), this, SLOT(readSock()));
}


void clientSock::connected()
{
    qDebug() << "Connected!";
}

void clientSock::disconnected()
{
    qDebug() << "Disconnected!";
}

void clientSock::readSock()
{
    qDebug() << "Reading...";
    QByteArray bytes;

        while(csock->canReadLine())
            bytes = csock->readAll();
        QString myString(bytes);
        qDebug() << myString ;
}

void clientSock::writeSock(QByteArray dataToSend)
{
    if (csock!=NULL)
    {
        csock->write(dataToSend.data(), dataToSend.length());
        csock->flush();
    }
}
