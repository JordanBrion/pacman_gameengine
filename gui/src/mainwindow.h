#include "trianglerenderer.h"
#include <QWidget>

class VulkanWindow;

class QTabWidget;
class QPlainTextEdit;
class QLCDNumber;

#include <QVulkanInstance>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class VulkanWindow : public QVulkanWindow
{
    Q_OBJECT

public:
    QVulkanWindowRenderer *createRenderer() override;

signals:
    void vulkanInfoReceived(const QString &text);
    void frameQueued(int colorValue);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();

public slots:
    void onVulkanInfoReceived(const QString &text);
    void onFrameQueued(int colorValue);
    void onGrabRequested();

private:
    QVulkanInstance inst;
    VulkanWindow m_window;
    QTabWidget *m_infoTab;
    QPlainTextEdit *m_info;
    QLCDNumber *m_number;
    Ui::MainWindow *ui;
};

class VulkanRenderer : public TriangleRenderer
{
public:
    VulkanRenderer(VulkanWindow *w);

    void initResources() override;
    void startNextFrame() override;
};
