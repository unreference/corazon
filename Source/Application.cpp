#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Application.hpp"

Application::Application()
  : m_Window( nullptr )
{
  if ( !Initialize() )
  {
    return;
  }
}

Application::~Application()
{
  Terminate();
}

void Application::Run()
{
  while ( !glfwWindowShouldClose( m_Window ) )
  {
    Update();
    Render();
  }

  Terminate();
}

void Application::FrameBufferSizeCallback( GLFWwindow * window, int width,
                                           int height )
{
  glViewport( 0, 0, width, height );
}

bool Application::Initialize()
{
  if ( !glfwInit() )
  {
    std::cerr << "Failed to initialize GLFW!" << std::endl;
    return false;
  }

  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
  glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

  m_Window = glfwCreateWindow( 1280, 720, "Corazon", nullptr, nullptr );
  if ( !m_Window )
  {
    std::cerr << "Failed to create GLFW window!" << std::endl;
    glfwTerminate();
    return false;
  }

  glfwMakeContextCurrent( m_Window );
  glfwSetWindowSizeCallback( m_Window, FrameBufferSizeCallback );

  if ( !gladLoadGLLoader(
         reinterpret_cast<GLADloadproc>( glfwGetProcAddress ) ) )
  {
    std::cerr << "Failed to initialize GLAD!" << std::endl;
    glfwTerminate();
    return false;
  }

  return true;
}

void Application::GetInput()
{
  if ( glfwGetKey( m_Window, GLFW_KEY_ESCAPE ) == GLFW_PRESS )
  {
    glfwSetWindowShouldClose( m_Window, true );
  }
}

void Application::Update()
{
  GetInput();
}

void Application::Render()
{
  glClearColor( 0.5f, 0.5f, 0.5f, 1.0f );
  glClear( GL_COLOR_BUFFER_BIT );

  glfwSwapBuffers( m_Window );
  glfwPollEvents();
}

void Application::Terminate()
{
  if ( m_Window )
  {
    glfwDestroyWindow( m_Window );
    m_Window = nullptr;
  }

  glfwTerminate();
}
