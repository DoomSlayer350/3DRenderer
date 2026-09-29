#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// I accidentally got rid of local commit history I rendered a triangle and then git reset so i could test myself and proceeded to force push to branch 
void framebuffer_size_callback(GLFWwindow* Window, int Width, int Height);
void processInput(GLFWwindow* Window);

const char* VertexShaderSource = 
"#version 330 core\n"
"layout(location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* FragmentShaderSource =
"#version 330 core\n"
"out vec4 FragmentColour;\n"
"void main()\n"
"{\n"
"FragmentColour = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\0";

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

    //Vertex Shader
    unsigned int VertexShader;
    VertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(VertexShader, 1, &VertexShaderSource, NULL);
    glCompileShader(VertexShader);

    int success;
    char InfoLog[512];
    glGetShaderiv(VertexShader, GL_COMPILE_STATUS, &success);

    if(!success){
        glGetShaderInfoLog(VertexShader, 512, NULL, InfoLog);
        std::cout<<"FAILED TO COMPILE VERTEX SHADER ---> "<<InfoLog<<std::endl;
    }

    //Fragment Shader
    unsigned int FragmentShader;
    FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(FragmentShader, 1, &FragmentShaderSource, NULL);
    glCompileShader(FragmentShader);

    glGetShaderiv(FragmentShader, GL_COMPILE_STATUS, &success);

    if(!success){
        glGetShaderInfoLog(FragmentShader, 512, NULL, InfoLog);
        std::cout<<"FAILED TO COMPILE FRAGMENT SHADER ---> "<<InfoLog<<std::endl;
    }

    //Shader Program
    unsigned int ShaderProgram;
    ShaderProgram = glCreateProgram();

    glAttachShader(ShaderProgram, VertexShader);
    glAttachShader(ShaderProgram, FragmentShader);
    glLinkProgram(ShaderProgram);

    glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(ShaderProgram, 512, NULL, InfoLog);
        std::cout<<"FAILED TO LINK SHADERS IN SHADER PROGRAM ---> "<<InfoLog<<std::endl;
    }

    glUseProgram(ShaderProgram);
    
    glDeleteShader(VertexShader);
    glDeleteShader(FragmentShader);

    // Vertex Array

    unsigned int VertexArrayObject;
    glGenVertexArrays(1, &VertexArrayObject);
    glBindVertexArray(VertexArrayObject);

    //Vertex Buffer Object
    unsigned int VertexBufferObject;
    glGenBuffers(sizeof(1), &VertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Vertex Attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    // Render Loop
    while(!(glfwWindowShouldClose(Window)))
    {
        processInput(Window);

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(ShaderProgram);
        glBindVertexArray(VertexArrayObject);
        glDrawArrays(GL_TRIANGLES, 0, 3);


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