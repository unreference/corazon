#pragma once

class GLFWwindow;

class Application
{
public:
  Application();
  ~Application();

  void Run();

private:
  static void FrameBufferSizeCallback( GLFWwindow * window, int width,
                                       int height );

  bool Initialize();
  void GetInput();
  void Update();
  void Render();
  void Terminate();

  GLFWwindow * m_Window;
};
