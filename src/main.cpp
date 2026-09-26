#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// I accidentally got rid of local commit history I rendered a triangle and then git reset so i could test myself and proceeded to force push to branch 

void framebuffer_size_callback(GLFWwindow* Window, int Width, int Height);
void processInput(GLFWwindow* Window);

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
    
    float vertices[] = {
        -0.7f, -0.2f, 0.0f,
        0.7f, -0.2f, 0.0f,
        0.0f, 0.7f, 0.0f
    };

    unsigned int VertexBufferObject;
    glGenBuffers(sizeof(1), &VertexBufferObject);

    glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);

    // Render Loop
    while(!(glfwWindowShouldClose(Window)))
    {
        processInput(Window);

        glClear(GL_COLOR_BUFFER_BIT);

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

void processInput(GLFWwindow* Window)
{
    if(glfwGetKey(Window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(Window, true);
    }
    if(glfwGetKey(Window, GLFW_KEY_1) == GLFW_PRESS){
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    }
    if(glfwGetKey(Window, GLFW_KEY_2) == GLFW_PRESS){
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    }
    if(glfwGetKey(Window, GLFW_KEY_0) == GLFW_PRESS){
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }
}