#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(){
    glfwInit();
    GLFWwindow* Window;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwCreateWindow(600,600,"3D Renderer",NULL,NULL);
    std::cout<<"Program ran successfully"<<std::endl;
    glfwTerminate();
    return 0;
}
