#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* Window;
    Window = glfwCreateWindow(600,600,"3D Renderer",NULL,NULL);
    if (Window == NULL)
    {
        glfwTerminate();
        std::cout<<"Window == NULL"<<std::endl;
        return -1;
    }
    std::cout<<"Program ran successfully"<<std::endl;
    glfwTerminate();
    return 0;
}
