# wave-packets

This project is supposed to show my thought process on how to simulate wave-packets using OpenGL.

## requirements

  - [GLFW] (https://www.glfw.org) for window creation
  - [GLEW] (https://glew.sourceforge.net) OpenGL extension
  - [GLM] (https://github.com/g-truc/glm) OpenGL math library

## build

building this project using the provided cmake file requires the depencies to be build inside the project folder.
The building of the libaries is documented on the respective websites.

    cd /path/to/project
    mkdir external

Putting all the required libraries in this external folder and building them in place enables the use of the provided cmakelists.txt file.
The file structure should look like this:

    /project
      CMakeLists.txt
      basic.shader
      main.cpp
      /src
      /external
        /glfw
        /glew
        /glm-master

Otherwise changes can be made to this file or installing the requirements and using an other build method are also possibilities.

Maybe I will update the cmakelists file in the future, so that the project can be build out of the box.
