

#include "BRP_Quad.h"

namespace SGL {

    /* ***************************************************************************************** */
    BRP_Quad::BRP_Quad(
        const BRP_Camera& camera,
        const BRP_Shader& shader,
        const Vector3<float>& p1,
        const Vector3<float>& p2,
        const Vector3<float>& p3,
        const Vector3<float>& p4,
        const bool setStatic
    ) {
        m_pCamera = &camera;
        m_pShaderGLSL = &shader;
        m_pBRP_ShaderUniformManager = new BRP_ShaderUniformManager();
        m_IsStatic = setStatic;

        std::vector<Drawable::BufferDataType> vertex = {
            p1.x, p1.y, p1.z,
            p2.x, p2.y, p2.z,
            p3.x, p3.y, p3.z,
            p4.x, p4.y, p4.z
        };

        std::vector<Drawable::IndicesDataType> indices = {
            0, 1, 3, 1, 2, 3
        };

        m_Drawable.setBufferData(0, 3, std::move(vertex));
        m_Drawable.setIndices(std::move(indices));
        m_Drawable.setDrawMethod(m_IsStatic ? DrawMethod::Static : DrawMethod::Dynamic);
        m_Drawable.setDrawMode(DrawMode::Triangles);
        m_Drawable.configure();
    }


    /* ***************************************************************************************** */
    BRP_Quad::~BRP_Quad(
    ) noexcept {
        if (m_pBRP_ShaderUniformManager) {
            delete m_pBRP_ShaderUniformManager;
            m_pBRP_ShaderUniformManager = nullptr;
        }
    }


    /* ***************************************************************************************** */
    auto BRP_Quad::setPoints(
        const Vector3<float>& p1,
        const Vector3<float>& p2,
        const Vector3<float>& p3,
        const Vector3<float>& p4
    ) -> void {
        if (m_IsStatic) return;

        std::vector<Drawable::BufferDataType> vertex = {
            p1.x, p1.y, p1.z,
            p2.x, p2.y, p2.z,
            p3.x, p3.y, p3.z,
            p4.x, p4.y, p4.z
        };

        m_Drawable.setBufferData(0, 3, std::move(vertex));
        m_Drawable.configure();
    }


    /* ***************************************************************************************** */
    auto BRP_Quad::draw(
    ) const noexcept -> void {
        m_pShaderGLSL->setActive();
        m_pShaderGLSL->setMatrix4("uTransform", m_pCamera->getMatrix4());
        m_pBRP_ShaderUniformManager->activateAll(m_pShaderGLSL);
        m_Drawable.draw();
    }

}