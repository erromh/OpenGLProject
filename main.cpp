#include "App.h"

int main(int argc, char **argv)
{
    glEnable(GL_DEPTH_TEST);
    glutInit(&argc, argv);

    App app(800, 900, "Title");

    app.startApplication();

    return 0;
}
