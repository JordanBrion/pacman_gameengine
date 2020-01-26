#include "mainwindow.h"

#include <QVulkanFunctions>
#include <QVBoxLayout>

#include "scene3drenderer.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow()
    : QMainWindow()
    , m_pUi(new Ui::MainWindow)
    , m_context(xxffi::create_vulkan_context())
    , m_vulkanInstance()
{
    m_pUi->setupUi(this);
    m_vulkanInstance.setVkInstance(reinterpret_cast<VkInstance>(m_context.instance));
    m_scene.setVulkanInstance(&m_vulkanInstance);
    QWidget *wrapper = QWidget::createWindowContainer(&m_scene);

    m_pUi->verticalLayout->addWidget(wrapper, 5);
    resize(1024, 768);
}
