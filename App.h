#pragma once
#include <GL/glew.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <gl/glut.h>
#include <glm/glm.hpp>

#include <filesystem>
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


  private:

    void handleKeys(unsigned char key);

    static void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    // const char *_xmlPath; // std::filesystem::current_path().string() + "/XmlData/test.xml";

  public:
    App(int width, int height, const char *title);
    ~App();

    void startApplication();
};
