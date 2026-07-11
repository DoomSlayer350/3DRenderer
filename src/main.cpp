#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int Width, int Height);

int main(){
    glfwInit();
    if (!glfwInit())
        return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //We are using GLFW 3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //We are using GLFW 3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Use the core profile not compatability (use modern OpenGL)
    GLFWwindow* window;
    int windowWidth = 600;
    int windowHeight = 600;
    window = glfwCreateWindow(windowWidth,windowHeight,"MyWindow",NULL,NULL);
    if(window == NULL)
    {
        std::cout<<"Window == NULL"<<std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout<<"Couldn't load GLAD"<<std::endl;
        return -1;
    }
    
    glViewport(0, 0, windowWidth, windowHeight);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); //Resize the viewport anytime the user resizes the window
    
    //Render loop below

    while(!glfwWindowShouldClose(window)){
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    std::cout<<"Program ran successfully"<<std::endl;
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int Width, int Height)
{
    glViewport(0,0,Width,Height);
}