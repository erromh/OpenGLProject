//
// Segment.h
// 
// ��������: ����� ���������� �� ������������� ��������.
//

#pragma once
#include <GLFW/glfw3.h>

class Segment
{
  private:
    // ��������� ����� �������
    float _x1, _y1, _z1;

    // �������� ����� �������
    float _x2, _y2, _z2;

  public:
    Segment(float x1, float y1, float z1, float x2, float y2, float z2);

    // ����� ��� ����������� ��������
    void drawSegment() const;
};
