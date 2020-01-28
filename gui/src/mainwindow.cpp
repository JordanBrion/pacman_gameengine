#include "mainwindow.h"

#include <QVulkanFunctions>
#include <QVBoxLayout>

#include "scene3drenderer.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow()
    : QMainWindow()
    , m_pUi(new Ui::MainWindow)
    , m_vulkanInstance()
    , m_pContext(nullptr)
    , m_scene()
{
    m_pUi->setupUi(this);
    QWidget *wrapper = QWidget::createWindowContainer(&m_scene);
    m_pContext = xxffi::create_vulkan_context(wrapper->width(),
                                              wrapper->height());
    m_vulkanInstance.setVkInstance(reinterpret_cast<VkInstance>(xxffi::get_vulkan_instance(m_pContext)));
    if (!m_vulkanInstance.create()) {
        qFatal("Cannot create vulkan instance");
    }
    m_scene.setVulkanInstance(&m_vulkanInstance);
    m_pUi->verticalLayout->addWidget(wrapper, 5);
    resize(1024, 768);
}
