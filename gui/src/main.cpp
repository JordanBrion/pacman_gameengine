#include <QApplication>
#include <QDebug>

#include "editor.h"

int main(int argc, char *argv[])
{
    Editor editor(argc, argv);
    return editor.exec();
}
