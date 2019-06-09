#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

float vertices[] = {
  -.5f, -.5f, .0f,
  .5f, -.5f, .0f,
  .0f, .5f, .5f
};

void framebuffer_size_callback( GLFWwindow*, 
                                int width, 
                                int height);

void processInput(GLFWwindow* window);

int main()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(800, 
                                        600, 
                                        "LearnOpenGL",
                                        NULL,
                                        NULL);
  if(window == NULL) {
    std::cerr << "Failed to create GLFW windows" << std::endl;
    return -1;
  }
  glfwMakeContextCurrent(window);
  
  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Failed to init GLAD" << std::endl;
    return -1;
  }

  glViewport(0, 0, 800, 600);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  unsigned int VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData( GL_ARRAY_BUFFER, 
                sizeof(vertices),
                vertices,
                GL_STATIC_DRAW);

  while(!glfwWindowShouldClose(window)) {
    processInput(window);

    glClearColor(.2f, .3f, .3f, .0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}

void framebuffer_size_callback( GLFWwindow*, 
                                int width, 
                                int height)
{
  glViewport(0, 0, width, height);
}


void processInput(GLFWwindow* window)
{
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

