#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QString>

#define CONST_IP "127.0.0.1"
#define CONST_PORT 12000

class client : public QObject
{
    Q_OBJECT
public:
    client();

public slots:
    void writeSock(QByteArray bytes);
    void readSock();

private slots :

    void disconnect();
    void connected();

private:

    //var

    QString IPServ= CONST_IP ;
    int port = CONST_PORT ;
    QTcpSocket sockToServ;

    //func

    void tryToConnect() ;

};
#endif // CLIENT_H
