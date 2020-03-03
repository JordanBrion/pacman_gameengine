#ifndef SCENE3D_H
#define SCENE3D_H

#include <QVulkanWindow>

#include <xxffi/xxffi.h>

class Scene3d : public QVulkanWindow
{
public:
    Scene3d(xxffi::VulkanContext& context);
    QVulkanWindowRenderer* createRenderer() override;
private:
    xxffi::VulkanContext& m_context;
};

#endif // SCENE3D_H
