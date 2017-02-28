#include <QCoreApplication>
#include <QTextStream>
//#include <iostream>
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    QTextStream cin(stdin);
    QTextStream cout(stdout);
    QString message;
    cin >> message;
    QByteArray qba;
    qba = QByteArray::fromStdString(message.toLocal8Bit().data());
    for (int i =0; i<qba.length(); i++)
    {
    qba[i] = qba[i] + 1;
    }
    QString str = QString::fromUtf8(qba.toStdString().data());
    cout << str;
    _getwch();



    return a.exec();
}
