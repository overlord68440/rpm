#include "mainwindow.h"
#include <QApplication>
#include "client.h"

#include <unistd.h>
int main(int argc, char *argv[])
{
    sleep (10) ;
    qDebug() << "gogo" ;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
