#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(){
    glfwInit();
    GLFWwindow* Window;
    glfwWindowHint(GL_MAJOR_VERSION, 3);
    glfwWindowHint(GL_MINOR_VERSION, 3);
    glfwCreateWindow(600,600,"3D Renderer",NULL,NULL);
    std::cout<<"Program ran successfully"<<std::endl;
    glfwTerminate();
    return 0;
}
