#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#include <xxffi/xxffi.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    hello_from_rust();
    const auto serialized = serialize_rust_struct();
    qDebug() << "serialized !!" << serialized;
    delete[] serialized;
    return a.exec();
}
