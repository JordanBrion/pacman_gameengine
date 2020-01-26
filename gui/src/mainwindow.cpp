#include "mainwindow.h"

#include <QVulkanFunctions>
#include <QVBoxLayout>

#include "scene3drenderer.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow()
    : QMainWindow()
    , m_pUi(new Ui::MainWindow)
    , m_vulkanInstance()
    , m_pContext(xxffi::create_vulkan_context())
    , m_scene()
{
    m_pUi->setupUi(this);
    if (!m_vulkanInstance.create()) {
        qFatal("Cannot create vulkan instance");
    }
    xxffi::import_vulkan_instance(m_pContext, reinterpret_cast<uint64_t>(m_vulkanInstance.vkInstance()));
    m_scene.setVulkanInstance(&m_vulkanInstance);
    QWidget *wrapper = QWidget::createWindowContainer(&m_scene);
    m_pUi->verticalLayout->addWidget(wrapper, 5);
    resize(1024, 768);
}
