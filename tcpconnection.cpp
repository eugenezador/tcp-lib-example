#include "tcpconnection.h"
#include "ui_tcpconnection.h"

TcpConnection::TcpConnection(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TcpConnection)
{
    ui->setupUi(this);
}

TcpConnection::~TcpConnection()
{
    delete ui;
}

