#include "client.h"
#include <unistd.h>

client::client()
{
    connect(&sockToServ, SIGNAL(connected()), this, SLOT(connected()));
    connect(&sockToServ, SIGNAL(disconnected()), this, SLOT(disconnect()));
    connect(&sockToServ, SIGNAL(readyRead()), this, SLOT(readSock()));
    tryToConnect();

}

void client::tryToConnect()
{
    qDebug() << "Connecting...";
    sockToServ.connectToHost(IPServ, port);
}

void client::connected()
{
    qDebug() << "Connected!";
}

void client::disconnect()
{
    qDebug() << "Disconnected!";
}

void client::writeSock(QByteArray dataToSend)
{
    sockToServ.write(dataToSend.data(), dataToSend.length());
    sockToServ.flush();
}

void client::readSock()
{
   // qDebug() << "Reading...";
    QString data;
        while(sockToServ.canReadLine())
            data = sockToServ.readLine();
    qDebug() << data;
}
