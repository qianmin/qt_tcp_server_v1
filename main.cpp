#include <QCoreApplication>
#include<my_tcp.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    my_tcp s;
    s.start();
    return a.exec();
}
