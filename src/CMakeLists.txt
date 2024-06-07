INCLUDE_DIRECTORIES(
    ./include
    ../external/glew/include
    ../external/glm-master/glm
    ../external/glfw/include)

add_library(renderClasses 
    vertexArray.cpp
    vertexBuffer.cpp
    shader.cpp
    renderer.cpp
    )