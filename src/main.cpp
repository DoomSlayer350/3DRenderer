#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* Window, int Width, int Height);

int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* Window;
    int WindowWidth = 600;
    int WindowHeight = 600;
    Window = glfwCreateWindow(WindowWidth,WindowHeight,"3D Renderer",NULL,NULL);
    if (Window == NULL)
    {
        glfwTerminate();
        std::cout<<"Window == NULL"<<std::endl;
        return -1;
    }

    glfwMakeContextCurrent(Window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        glfwTerminate();
        std::cout<<"Failed to initialise GLAD"<<std::endl;
        return -1;
    }
    glViewport(0,0,WindowWidth,WindowHeight);
    glfwSetFramebufferSizeCallback(Window, framebuffer_size_callback);

    while(!(glfwWindowShouldClose(Window)))
    {
        glfwSwapBuffers(Window);
        glfwPollEvents();
    }
    std::cout<<"Program ran successfully"<<std::endl;
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* Window, int Width, int Height)
{
    glViewport(0,0,Width,Height);
}