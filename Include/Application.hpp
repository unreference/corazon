#pragma once

#include "Types.hpp"

struct GLFWwindow;

constexpr double TimeStep = 1.0f / 60.0f;

class Application
{
public:
  Application();
  ~Application();

  void Run();

private:
  static void FrameBufferSizeCallback( GLFWwindow * window, s32 width,
                                       s32 height );

  bool Initialize();
  void GetInput();
  void Update();
  void Render();
  void Terminate();

  GLFWwindow * m_Window;
};
