#include "mainwindow.h"

#include <QApplication>

#include <xxffi/xxffi.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    request_create();
    return a.exec();
}
