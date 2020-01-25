#include "editor.h"

#include <QDebug>

/*!
 * \brief Editor::Editor
 * \param argc
 * \param argv
 */
Editor::Editor(int argc, char* argv[])
    : QApplication(argc, argv)
    , m_mainWindow()
    , m_logic(init_editor_logic())
{
    hello_from_rust();
    const auto serialized = serialize_rust_struct();
    qDebug() << "serialized !!" << serialized;
    delete[] serialized;
    const auto point = get_rust_instance();
    qDebug() << point.x;
    qDebug() << point.y;
    my_point_print_hello(&point);
    m_mainWindow.show();
}
