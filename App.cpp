#include "App.h"

App::App(int width, int height, const char *title)
{
    if (!glfwInit())
    {
        std::cerr << "Error GLFW initialization!" << std::endl;
        _mainWindow = nullptr;
        return;
    }

    _mainWindow = glfwCreateWindow(width, height, title, NULL, NULL);

    _camera = std::make_unique<CameraController>(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, -1.0f, 0.1f);

    if (!_mainWindow)
    {
        std::cerr << "Error in create GLFW window!" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(_mainWindow);

    glfwSetKeyCallback(_mainWindow, keyboardCallback);
}

void App::handleKeys(unsigned char key)
{
    _camera->isKeyPressed(key);
}

void App::keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    static App *_instance;

    if (_instance && action == GLFW_PRESS)
    {
        _instance->handleKeys(key);
    }
}

void App::startApplication()
{
    _segments = XMLParser::loadSegment("OpenglProject/XmlData/test.xml");

    while (!glfwWindowShouldClose(_mainWindow))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Отрисовка отрезков
        for (const auto &segment : _segments)
        {
            segment.drawSegment();
        }

        _camera->update();

        glfwSwapBuffers(_mainWindow);
        glfwPollEvents();
    }
}

App::~App()
{
    if (_mainWindow)
    {
        glfwDestroyWindow(_mainWindow);
    }
    glfwTerminate();
}
