#include "CameraController.h"

CameraController::CameraController(float xPos, float yPos, float zPos, float xFront, float yFront, float zFront,
                                   float cameraSpeed)
    : _xPos(xPos), _yPos(yPos), _zPos(zPos), _xFront(xFront), _yFront(yFront), _zFront(zFront),
      _cameraSpeed(cameraSpeed)
{
}

void CameraController::update()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(_xPos, _yPos, _zPos, _xPos + _xFront, _yPos + _yFront, _zPos + _zFront, 0.0f, 1.0f, 0.0f);
}

void CameraController::isKeyPressed(int key)
{
    switch (key)
    {
    case GLFW_KEY_W:
        _xPos += _xFront * _cameraSpeed;
        _yPos += _yFront * _cameraSpeed;
        _zPos += _zFront * _cameraSpeed;
        break;

    case GLFW_KEY_S:
        _xPos -= _xFront * _cameraSpeed;
        _yPos -= _yFront * _cameraSpeed;
        _zPos -= _zFront * _cameraSpeed;
        break;

    case GLFW_KEY_A:
        _xPos -= _zFront * _cameraSpeed;
        _zPos += _xFront * _cameraSpeed;
        break;

    case GLFW_KEY_D:
        std::cout << "D pressed\n";
        _xPos += _zFront * _cameraSpeed;
        _zPos -= _xFront * _cameraSpeed;
        break;

    default:
        std::cout << "Not such key\n";
        break;
    }
}
