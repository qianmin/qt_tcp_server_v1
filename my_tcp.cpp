#include "my_tcp.h"
#include<QDebug>
my_tcp::my_tcp()
{
    qDebug()<<"my_tcp";
}
void my_tcp::init_tcp()
{
    //建立服务器对象并开始初始化连接功能
    server= new  QTcpServer();
    connect(server,&QTcpServer::newConnection,this,&my_tcp::server_new_connect);
    qDebug()<<"init_tcp_and_listen";
}
void my_tcp::server_new_connect()
{
    //获取客户端连接
    socket = server->nextPendingConnection();
    //连接QTcpSocket的信号槽，以读取新数据
    QObject::connect(socket, &QTcpSocket::readyRead, this, &my_tcp::socket_read_data);
    qDebug() << "A Client connect!";
}
void my_tcp::socket_read_data()
{
    QByteArray buffer;
    //读取缓冲区数据
    buffer = socket->readAll();
    if(!buffer.isEmpty())
    {
        QString str = tr(buffer);
        //显示
        qDebug()<<"get_one_msg"<<str;
        socket_send_data("thanks");
    }
}
void my_tcp::socket_send_data(QString s)
{

    //获取文本框内容并以ASCII码形式发送
//    socket->write(ui->textEdit_send->toPlainText().toLatin1());
    socket->write(s.toLatin1());
    socket->flush();
    qDebug() << "Send: " << s;
}
//前面都是初始化函数，下面开始监听内容
void my_tcp::start()
{
    init_tcp();
    int port = 8888;
    //监听指定的端口
    if(!server->listen(QHostAddress::Any, port))
    {
        //若出错，则输出错误信息
        qDebug()<<server->errorString();
        return;
    }
}
