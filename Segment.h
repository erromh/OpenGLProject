//
// Segment.h
// 
// Описание: класс отвечающий за представление отрезков.
//

#pragma once
#include <GLFW/glfw3.h>

class Segment
{
  private:
    // Начальные точки отрезка
    float _x1, _y1, _z1;

    // Конечные точки отрезка
    float _x2, _y2, _z2;

  public:
    Segment(float x1, float y1, float z1, float x2, float y2, float z2);

    // Метод для отображения отрезков
    void drawSegment() const;
};
