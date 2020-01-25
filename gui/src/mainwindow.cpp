#include "mainwindow.h"

#include <QVulkanFunctions>
#include <QVBoxLayout>

#include "scene3drenderer.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow() :
    QMainWindow(),
    m_pUi(new Ui::MainWindow),
    m_vulkanInstance(),
    m_scene()
{
    m_pUi->setupUi(this);
    if (!m_vulkanInstance.create())
        qFatal("Failed to create Vulkan instance: %d", m_vulkanInstance.errorCode());

    m_vulkanInstance.setLayers(QByteArrayList() << "VK_LAYER_LUNARG_standard_validation");
    m_scene.setVulkanInstance(&m_vulkanInstance);
    QWidget *wrapper = QWidget::createWindowContainer(&m_scene);

    m_pUi->verticalLayout->addWidget(wrapper, 5);
    resize(1024, 768);
}
