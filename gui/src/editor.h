#ifndef     EDITOR_H
#define     EDITOR_H

#include <QApplication>

/*!
 * \brief Subclass of QApplication representing the editor
 */
class Editor :
        public QApplication {
public:
    Editor() = delete;
    Editor(int argc, char *argv[]);
    Editor(const Editor& other) = delete;
    Editor(Editor&& other) = delete;
    ~Editor() = default;
    Editor& operator=(const Editor& other) = delete;
    Editor& operator=(Editor&& other) = delete;

private:
};

#endif      // EDITOR_H
