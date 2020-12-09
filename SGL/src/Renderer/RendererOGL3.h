/**
* 
* 
* 
*/

#ifndef _SGL_RENDERER_OGL3_H_
#define _SGL_RENDERER_OGL3_H_

#include "SGLCore.h"
#include "Renderer.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace SGL {

    class SGL_API RendererOGL3 : public Renderer
    {
    public:

        /**
         * Default constructor.
         * 
         * Note: this doesn't actually create the renderer. Call create() to do so.
         */
        RendererOGL3(
        ) noexcept;


        /**
         * Create a new OpenGL 3.3 renderer.
         *
         * @param width Window width for this renderer, in pixels.
         * @param height Window height for this renderer, in pixels.
         * @param title Window title for this renderer.
         * @exception Throws std::runtime_error if window couldn't be created.
         */
        RendererOGL3(
            const std::uint32_t width,
            const std::uint32_t height,
            const std::string& title
        );


        /**
         * Destructor.
         */
        ~RendererOGL3(
        );


        /**
         * Create a new OpenGL 3.3 renderer.
         *
         * @param width Window width for this renderer, in pixels.
         * @param height Window height for this renderer, in pixels.
         * @param title Window title for this renderer.
         * @exception Throws std::runtime_error if renderer couldn't be created.
         */
        auto create(
            const std::uint32_t width,
            const std::uint32_t height,
            const std::string& title
        ) -> void;


        /**
         * Destroy this renderer. Destructor calls it automatically.
         */
        auto destroy(
        ) noexcept -> void;


        auto running(
        ) const noexcept -> bool override;


        auto clear(
            const Color& color
        ) const noexcept -> void override;


        auto draw(
        ) const noexcept -> void override;


        auto close(
            const bool forceQuit = false
        ) const noexcept -> void override;


        auto setWidth(
            const std::uint32_t newWidth
        ) noexcept -> void override;


        auto getWidth(
        ) const noexcept -> std::uint32_t override;


        auto setHeight(
            const std::uint32_t newWidth
        ) noexcept -> void override;


        auto getHeight(
        ) const noexcept -> std::uint32_t override;


        auto setTitle(
            const std::string& newTitle
        ) noexcept -> void override;


        auto getTitle(
        ) const noexcept -> const char* override;


        /*! @brief Returns pointer to GLFW window.
        *
        */
        auto getGLFWwindow(
        ) const noexcept -> GLFWwindow* override;


    private:
        std::uint32_t m_Width;
        std::uint32_t m_Height;
        std::string m_Title;

        mutable bool m_QuitRequested;
        GLFWwindow* m_pGLFWwindow;
    };

}  /* namespace SGL */

#endif  /* _SGL_RENDERER_OGL3_H_ */