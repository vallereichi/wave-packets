# wave-packets

This project is supposed to show my thought process on how to simulate wave-packets using OpenGL.

## dependenncies

  - [GLFW] (https://www.glfw.org) for window creation
  - [GLEW] (https://glew.sourceforge.net) OpenGL extension
  - [GLM] (https://github.com/g-truc/glm) OpenGL math library

## build

This project can be build using the provided CMakeLists.txt file.
Else the dependencies must be linked otherwise.

###Building with cmake

    cd path/to/repository
    mkdir build
    cd build
    cmake -S .. -B .
    cmake --build
