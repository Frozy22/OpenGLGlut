#include <Windows.h>
#include <glut.h>
#include <algorithm>
#include <vector>
#include <cstdarg>
#include "Utility.h"
#include "Input.h"
#include "GameObject.h"
#include "Triangle.h"

using namespace Utility; 

Triangle::Triangle(Vector2f position, float rotation, Vector2f scale, Color color)
    :GameObject(position, rotation, scale, color, 3, Vector2f(-1, -1),Vector2f(0, 1),Vector2f(1, -1)) {
    
}

void Triangle::update()
{
    float hor = 0;
    float ver = 0;
    if (Input::getNormalKey('w')) ver = speed;
    if (Input::getNormalKey('s')) ver = -speed;
    if (Input::getNormalKey('d')) hor = speed;
    if (Input::getNormalKey('a')) hor = -speed;
    position += Vector2f(hor,ver);
}
