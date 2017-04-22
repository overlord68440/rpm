#include <QCoreApplication>
#include "serv.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    serv *test = new serv() ;
    test->start() ;
    return a.exec();
}
