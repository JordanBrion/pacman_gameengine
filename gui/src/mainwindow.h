#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QVulkanInstance>

#include "scene3d.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();

private:
    Ui::MainWindow *m_pUi;
    QVulkanInstance m_vulkanInstance;
    Scene3d m_scene;
};

#endif
