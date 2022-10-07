#include "tcpconnection.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TcpConnection w;
    w.show();
    return a.exec();
}
