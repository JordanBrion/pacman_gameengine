#ifndef SCENE_3D_RENDERER_H
#define SCENE_3D_RENDERER_H

#include <QVulkanWindow>

#include <xxffi/xxffi.h>

class Scene3dRenderer : public QVulkanWindowRenderer
{
public:
    Scene3dRenderer(QVulkanWindow& window,
                    xxffi::VulkanContext& context,
                    bool msaa = false);
    void initResources() override;
    void initSwapChainResources() override;
    void releaseSwapChainResources() override;
    void releaseResources() override;
    void startNextFrame() override;
protected:
    VkShaderModule createShader(const QString &name);
    QVulkanWindow& m_window;
    xxffi::VulkanContext& m_context;
    QVulkanDeviceFunctions *m_devFuncs;
    VkDeviceMemory m_bufMem = VK_NULL_HANDLE;
    VkBuffer m_buf = VK_NULL_HANDLE;
    VkDescriptorBufferInfo m_uniformBufInfo[QVulkanWindow::MAX_CONCURRENT_FRAME_COUNT];
    VkDescriptorPool m_descPool = VK_NULL_HANDLE;
    VkDescriptorSetLayout m_descSetLayout = VK_NULL_HANDLE;
    VkDescriptorSet m_descSet[QVulkanWindow::MAX_CONCURRENT_FRAME_COUNT];
    VkPipelineCache m_pipelineCache = VK_NULL_HANDLE;
    VkPipelineLayout m_pipelineLayout = VK_NULL_HANDLE;
    VkPipeline m_pipeline = VK_NULL_HANDLE;
    QMatrix4x4 m_proj;
    float m_rotation = 0.0f;
};

#endif
