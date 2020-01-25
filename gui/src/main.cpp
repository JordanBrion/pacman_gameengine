#include <QApplication>
#include <QDebug>

#include "mainwindow.h"
#include "editor.h"


int main(int argc, char *argv[])
{
    Editor editor(argc, argv);

    MainWindow mainWindow;
    mainWindow.resize(1024, 768);
    mainWindow.show();

    return editor.exec();
}
