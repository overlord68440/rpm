#ifndef CLIENTSOCK_H
#define CLIENTSOCK_H

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QtNetwork>

class clientSock : public QObject
{
    Q_OBJECT
public:
    clientSock(QTcpSocket *sock) ;
    QTcpSocket *csock ;
public slots :
    void readSock();
    void writeSock(QByteArray dataToSend);


private slots:
    void disconnected();
    void connected();
};

#endif // CLIENTSOCK_H
