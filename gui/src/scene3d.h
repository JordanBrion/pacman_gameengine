#ifndef SCENE3D_H
#define SCENE3D_H

#include <QVulkanWindow>

class Scene3d : public QVulkanWindow
{
public:
    QVulkanWindowRenderer* createRenderer() override;
};

#endif // SCENE3D_H
