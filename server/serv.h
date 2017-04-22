#ifndef SERV_H
#define SERV_H

#include <QObject>
#include <QString>
#include <QList>
#include <QLocalServer>
#include <QLocalSocket>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtConcurrent/QtConcurrent>

#include "clientsock.h"


#define FILE_TEMP_NAME "dataExchange"
using namespace std ;

int num() ;

class serv : public QTcpServer
{
    Q_OBJECT

public:

    explicit serv(QObject *parent = 0);
    ~serv();

    void start();

private :
    //var
    QString path = QDir::currentPath() ;
    QFile tempFile ;
    QStringList arguments ;
    QProcess *myProcess ;
    QLocalSocket *mpv=NULL;     // socket to communicate with mpv
    QList<clientSock*> clientList;      //sockets to client
    //QFutureSynchronizer<void> sync ;

    //fun
    void runMPV() ;
    void connectToMPV() ;
    void newClient(QTcpSocket sock) ;
    void sendToMPV(QByteArray bytes);
    //void runClientThread() ;

    void createCommunicationFile();
private slots :

    void connection() ;


signals :
    void dataReveived(QString s) ;


};

#endif // SERV_H
