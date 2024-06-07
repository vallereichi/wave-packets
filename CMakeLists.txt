cmake_minimum_required(VERSION 3.5)
project(wavePackets)

add_executable(${PROJECT_NAME} main.cpp)


#linking glfw
add_subdirectory(external/glfw)
target_include_directories(${PROJECT_NAME} PUBLIC external/glfw/include)
target_link_directories(${PROJECT_NAME} PRIVATE external/glfw/build/src)
target_link_libraries(${PROJECT_NAME} glfw)

#linking glm
add_subdirectory(external/glm-master)
target_include_directories(${PROJECT_NAME} PUBLIC external/glm-master/glm)
target_link_directories(${PROJECT_NAME} PRIVATE external/glm-master/build/glm)
target_link_libraries(${PROJECT_NAME} glm)

#linking glew
add_subdirectory(external/glew)
target_include_directories(${PROJECT_NAME} PUBLIC external/glew/include)
target_link_directories(${PROJECT_NAME} PRIVATE external/glew/lib)
target_link_libraries(${PROJECT_NAME} "-lGLEW -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")

#linking render classes
add_subdirectory(src)
target_include_directories(${PROJECT_NAME} PRIVATE src/include)
target_link_directories(${PROJECT_NAME} PRIVATE src)
target_link_libraries(${PROJECT_NAME} renderClasses)



