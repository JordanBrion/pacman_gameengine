#include "scene3d.h"

#include "scene3drenderer.h"

QVulkanWindowRenderer *Scene3d::createRenderer()
{
    return new Scene3dRenderer(this);
}
