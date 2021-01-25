

#include "Triangle.h"

namespace SGL {

    /* ***************************************************************************************** */
    Triangle::Triangle(
        const Camera& camera,
        const ShaderGLSL& shader,
        const Vector3<float>& p1,
        const Vector3<float>& p2,
        const Vector3<float>& p3,
        const Color& color,
        const bool setStatic
    ) {
        m_pCamera = &camera;
        m_pShaderGLSL = &shader;
        m_Color = color;
        m_IsStatic = setStatic;

        std::vector<Drawable::BufferDataType> vertex = {
            p1.x, p1.y, p1.z,
            p2.x, p2.y, p2.z,
            p3.x, p3.y, p3.z
        };

        std::vector<Drawable::IndicesDataType> indices = {
            0, 1, 2
        };

        m_Drawable.setBufferData(0, 3, std::move(vertex));
        m_Drawable.setIndices(std::move(indices));
        m_Drawable.setDrawMethod(m_IsStatic ? DrawMethod::Static : DrawMethod::Dynamic);
        m_Drawable.setDrawMode(DrawMode::Triangles);
        m_Drawable.configure();
    }


    /* ***************************************************************************************** */
    Triangle::~Triangle(
    ) {

    }


    /* ***************************************************************************************** */
    auto Triangle::setPoints(
        const Vector3<float>& p1,
        const Vector3<float>& p2,
        const Vector3<float>& p3
    ) -> void {
        if (m_IsStatic) return;

        std::vector<Drawable::BufferDataType> vertex = {
            p1.x, p1.y, p1.z,
            p2.x, p2.y, p2.z,
            p3.x, p3.y, p3.z
        };

        m_Drawable.setBufferData(0, 3, std::move(vertex));
        m_Drawable.configure();
    }


    /* ***************************************************************************************** */
    auto Triangle::draw(
    ) const noexcept -> void {
        m_pShaderGLSL->setActive();
        m_pShaderGLSL->setMatrix4("uTransform", m_pCamera->getMatrix4());
        m_pShaderGLSL->setVector4("uColor", m_Color.toVec4());
        m_Drawable.draw();
    }

}