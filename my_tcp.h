#ifndef MY_TCP_H
#define MY_TCP_H
#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

class my_tcp:public QObject
{
    Q_OBJECT
public:
    my_tcp();

public:
    void init_tcp();
    void server_new_connect();
    void socket_read_data();
    void socket_send_data(QString s);
    void start();

private:
    QTcpServer* server;
    QTcpSocket* socket;

};

#endif // MY_TCP_H
