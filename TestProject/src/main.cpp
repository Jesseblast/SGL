/**
* This is a test project suitable for testing SGL functionality.
*
*
*/

#include "SGL.h"

auto main(int argc, char** argv) -> int try {

    SGL::Window window(SGL::RendererType::OpenGL3, 640, 480, "Moi vain!");
    SGL::Input input(window);

    while (window.running()) {
        window.clear({ 0, 255, 0 });
        window.draw();

        if (input.getKey(77))
            window.close();
    }

    return EXIT_SUCCESS;
}
catch (const std::runtime_error& e) {
    std::cerr << e.what();
    return EXIT_FAILURE;
}
catch (...) {
    std::cerr << "Unknown error!";
    return EXIT_FAILURE;
}