#include "scene3d.h"

#include "scene3drenderer.h"

Scene3d::Scene3d(xxffi::VulkanContext& context)
    : QVulkanWindow()
    , m_context(context)
{
}

QVulkanWindowRenderer *Scene3d::createRenderer()
{
    return new Scene3dRenderer(*this);
}
