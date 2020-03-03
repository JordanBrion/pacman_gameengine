#include "editor.h"

#include <QDebug>

#include <xxffi/xxffi.h>

/*!
 * \brief Editor::Editor
 * \param argc
 * \param argv
 */
Editor::Editor(int argc, char* argv[])
    : QApplication(argc, argv)
    , m_mainWindow()
{
    xxffi::hello_from_rust();
    const auto serialized = xxffi::serialize_rust_struct();
    qDebug() << "serialized !!" << serialized;
    delete[] serialized;
    const auto point = xxffi::get_rust_instance();
    qDebug() << point.x;
    qDebug() << point.y;
    xxffi::my_point_print_hello(&point);
    m_mainWindow.show();
}
