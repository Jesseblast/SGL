/**
 * 
 * 
 * 
 */

#ifndef _SGL_DRAWABLE_H_
#define _SGL_DRAWABLE_H_

#include "SGLCore.h"

namespace SGL {

    /**
     * 
     */
    enum class DrawMethod : GLenum {
        Static = GL_STATIC_DRAW,
        Dynamic = GL_DYNAMIC_DRAW
    };


    /**
     * 
     */
    enum class DrawMode : GLenum {
        Points = GL_POINTS,
        Lines = GL_LINES,
        Triangles = GL_TRIANGLES
    };

    /**
     * The first parameter in the array specifies which vertex attribute in configures, and the
     * second parameter specifies its size.
     */
    using VertexAttributes = std::vector<std::array<GLuint, 2>>;


    class Drawable
    {
    public:

        /**
         * Default constructor.
         */
        SGL_API Drawable(
        );


        /**
         * Destructor.
         */
        SGL_API ~Drawable(
        ) noexcept;


        auto SGL_API create(
        ) -> void;


        auto SGL_API destroy(
        ) noexcept -> void;


        auto SGL_API setDrawMethod(
            const DrawMethod drawMethod
        ) noexcept -> void;


        auto SGL_API setDrawMode(
            const DrawMode drawMode
        ) noexcept -> void;


        auto SGL_API setData(
            const std::vector<float>& data
        ) -> void;


        auto SGL_API setIndices(
            const std::vector<GLuint>& indices
        ) -> void;


        auto SGL_API setVertexAttributes(
            const VertexAttributes& vertexAttributes
        ) -> void;


        auto SGL_API draw(
        ) const -> void;


    private:
        GLuint m_VertexArray, m_VertexBuffer, m_ElementBuffer;
        std::vector<float> m_Data;
        std::vector<GLuint> m_Indices;

        DrawMethod m_DrawMethod;
        DrawMode m_DrawMode;
        VertexAttributes m_VertexAttributes; // layout location and size 
        GLuint m_Stride;
    };

}

#endif  /* _SGL_DRAWABLE_H_ */