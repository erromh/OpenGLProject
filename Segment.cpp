#include "Segment.h"

Segment::Segment(float x1, float y1, float z1, float x2, float y2, float z2)
    : _x1(x1), _y1(y1), _z1(z1), _x2(x2), _y2(y2), _z2(z2)
{
}

void Segment::drawSegment() const
{
    glBegin(GL_LINES);

    glVertex3f(_x1, _y1, _z1);
    glVertex3f(_x2, _y2, _z2);

    glEnd();
}
