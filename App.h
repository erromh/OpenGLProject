#pragma once
#include <GL/glew.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <gl/glut.h>
#include <glm/glm.hpp>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>

#include "CameraController.h"
#include "Segment.h"
#include "XMLParser.h"

class App
{
  private:
    GLFWwindow *_mainWindow;

    std::vector<Segment> _segments;

    std::unique_ptr<CameraController> _camera;

    std::string fullPath;
    const char *xmlFilePath;

    static App *_instance;

  private:
    void handleKeys(unsigned char key);

    static void keyboardCallback1(GLFWwindow *window, int key, int scancode, int action, int mods);

  public:
    App(int width, int height, const char *title);
    ~App();

    void startApplication();
};
