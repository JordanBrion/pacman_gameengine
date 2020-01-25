#include <QApplication>
#include <QDebug>

#include "mainwindow.h"

#include <xxffi/xxffi.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.resize(1024, 768);
    mainWindow.show();

    hello_from_rust();
    const auto serialized = serialize_rust_struct();
    qDebug() << "serialized !!" << serialized;
    delete[] serialized;
    const auto point = get_rust_instance();
    qDebug() << point.x;
    qDebug() << point.y;
    my_point_print_hello(&point);

    return app.exec();
}
