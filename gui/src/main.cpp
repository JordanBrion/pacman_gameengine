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
    const auto instance = get_rust_instance();
    qDebug() << instance.x;
    qDebug() << instance.y;
    return a.exec();
}
