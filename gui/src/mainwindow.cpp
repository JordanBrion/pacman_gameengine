#include "mainwindow.h"

#include <QVulkanFunctions>
#include <QVBoxLayout>

#include "scene3drenderer.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow()
    : QMainWindow()
    , m_pUi(makeWindowUi(*this))
    , m_vulkanInstance()
    , m_pContext(xxffi::create_vulkan_context())
    , m_scene(*m_pContext)
{
    QWidget *wrapper = QWidget::createWindowContainer(&m_scene);
    m_vulkanInstance.setVkInstance(reinterpret_cast<VkInstance>(xxffi::get_vulkan_instance(m_pContext)));
    if (!m_vulkanInstance.create()) {
        qFatal("Cannot create vulkan instance");
    }
    m_scene.setVulkanInstance(&m_vulkanInstance);
    m_pUi->verticalLayout->addWidget(wrapper, 5);
    resize(1024, 768);
}

Ui::MainWindow* MainWindow::makeWindowUi(QMainWindow& window)
{
    Ui::MainWindow* pUi = new Ui::MainWindow;
    pUi->setupUi(&window);
    return pUi;
}
