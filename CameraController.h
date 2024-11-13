//
// CameraController.h
//
// ќписание: класс отвечающий за управление камерой
//

#pragma once
#include <GL/glew.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

class CameraController
{
  private:
    float _xPos, _yPos, _zPos;
    float _xFront, _yFront, _zFront;
    float _cameraSpeed;

  public:
    CameraController(float xPos, float yPos, float zPos, float xFront, float yFront, float zFront, float cameraSpeed);

    void update();

    void isKeyPressed(int key);
};
