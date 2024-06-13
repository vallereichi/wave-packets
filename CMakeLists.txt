cmake_minimum_required(VERSION 3.5)
project(wavePackets)

add_executable(${PROJECT_NAME} main.cpp)


#linking glfw
target_include_directories(${PROJECT_NAME} PUBLIC external/glfw/include)
target_link_directories(${PROJECT_NAME} PRIVATE external/glfw)
target_link_libraries(${PROJECT_NAME} glfw3)



#linking glew
target_include_directories(${PROJECT_NAME} PUBLIC external/glew/include)
target_link_directories(${PROJECT_NAME} PRIVATE external/glew/)
target_link_libraries(${PROJECT_NAME} "-lGLEW -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")

#linking render classes
add_subdirectory(src)
target_include_directories(${PROJECT_NAME} PRIVATE src/include)
target_link_directories(${PROJECT_NAME} PRIVATE src)
target_link_libraries(${PROJECT_NAME} renderClasses)

#linking wave functions
add_subdirectory(wavemagic)
target_include_directories(${PROJECT_NAME} PRIVATE wavemagic/include)
target_link_directories(${PROJECT_NAME} PRIVATE wavemagic)
target_link_libraries(${PROJECT_NAME} waveFunctions)




