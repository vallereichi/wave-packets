#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <assert.h>
#include <math.h>

#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>

//local includes
#include "debug.h"
#include "renderer.h"
#include "shader.h"
#include "vertexBuffer.h"
#include "vertexBufferLayout.h"
#include "vertexArray.h"


//function to initialize the window
GLFWwindow* InitWindow() {
    //initialize GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialze GLFW \n");
        getchar();
        return nullptr;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    std::cout << "MACOS!!" << std::endl;
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    //open a window and creating the open gl context
    GLFWwindow* window = glfwCreateWindow(1000, 800, "Wave Packet", NULL, NULL);
    if  (window == NULL) {
        fprintf(stderr, "failed to open a window \n");
        getchar();
        glfwTerminate();
        return nullptr;
    }
    
    unsigned int major = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MAJOR);
    unsigned int minor = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MINOR);
    std::cout << "oepngl shader version: " << major << "." << minor << std::endl;

    glfwMakeContextCurrent(window);

    //initialize GELW
    glewExperimental  = true;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "failed to initialize GLEW \n");
        getchar();
        glfwTerminate();
        return nullptr;
    }
    std::cout << "Using GL Version: " << glGetString(GL_VERSION) << std::endl;

    //enable user input
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    return window;
}



////////////////////////////////////////
//here starts the physics

//specifying the space in which the action happens
float left = 0.0;
float right = 500.0;
float top = 2.0;
float bottom = -2.0;


//simple sine wave
std::vector<float> wavePacket(int length, float start, float end, float width) {
    float increment;

    increment = (end - start)/length;

    std::vector<float> waveArray;

    float x;
    float y;

    for (int i = 0; i < length ; i++) {
        x = start + i * increment;
        y = (cos(0.5 * x) * exp(-(x*x)/(width*width)));

        waveArray.push_back(x);
        waveArray.push_back(y);
    }

    return waveArray;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN FUNCTION START
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main (void) {
    GLFWwindow* window = InitWindow();

    if (!window) {
        return -1;
    }


    //data that needs to be drawn
    std::vector<float> vec = wavePacket(10000, left, right, 50);
    float positions[vec.size()];

    std::cout << "Number of points on the screen: " << sizeof(positions)/sizeof(float) << std::endl;
    std::copy(vec.begin(), vec.end(), positions);

    {
        //add orthonormal projection
        glm::mat4 projection = glm::ortho(left, right, top, bottom);
        
        VertexArray va;
        VertexBuffer vb(positions, sizeof(positions));
        VertexBufferLayout layout;
        layout.AddFloat(2);
        
        
        Shader shader("../basic.shader");
        shader.Bind();
        shader.SetUniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
        shader.SetUniformMat4f("u_MVP", projection);

    do{
        //make changes before the next frame
        

        va.AddBuffer(vb, layout);
       



        Renderer renderer;


		renderer.Clear();
        shader.Bind();

        renderer.Draw(va, vb, shader);
       
		
		glfwSwapBuffers(window);
		glfwPollEvents();

    
	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

    }
    

    glfwTerminate();
    return 0;
}    