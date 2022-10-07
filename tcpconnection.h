#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TcpConnection; }
QT_END_NAMESPACE

class TcpConnection : public QMainWindow
{
    Q_OBJECT

public:
    TcpConnection(QWidget *parent = nullptr);
    ~TcpConnection();

private:
    Ui::TcpConnection *ui;
};
#endif // TCPCONNECTION_H
