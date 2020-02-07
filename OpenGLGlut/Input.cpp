#include <glut.h>
#include <conio.h>
#include "Input.h"

unsigned int Input::memoryNormal;
unsigned int Input::memoryNormalDown;
unsigned int Input::memoryNormalUp;
unsigned int Input::memorySpecial;
unsigned int Input::memorySpecialDown;
unsigned int Input::memorySpecialUp;

void Input::keyNormalDown(unsigned char key, int x, int y) {
    if(!getNormalKey(key)) memoryNormalDown |= (1 << key);
    memoryNormal |= (1 << key);
}
void Input::keyNormalUp(unsigned char key, int x, int y) {
    memoryNormal &= (0 << key);
    memoryNormalUp |= (1 << key);
}

void Input::keySpecialDown(int key, int x, int y) {
    if (!getSpecialKey(key)) memorySpecialDown |= (1 << key);
    memorySpecial |= (1 << key);
}
void Input::keySpecialUp(int key, int x, int y) {
    memorySpecial &= (0 << key);
    memorySpecialUp |= (1 << key);
}

bool Input::getNormalKey(unsigned char key) {
    return bool((1 << key) & memoryNormal);
}

bool Input::getNormalDown(unsigned char key)
{
    return bool((1 << key) & memoryNormalDown);
}

bool Input::getNormalUp(unsigned char key)
{
    return bool((1 << key) & memoryNormalUp);
}

bool Input::getSpecialKey(unsigned char key)
{
    return bool((1 << key) & memorySpecial);
}

bool Input::getSpecialDown(unsigned char key)
{
    return bool((1 << key) & memorySpecialDown);
}

bool Input::getSpecialUp(unsigned char key)
{
    return bool((1 << key) & memorySpecialUp);
}

void Input::Init()
{
    glutKeyboardFunc(keyNormalDown);
    glutKeyboardUpFunc(keyNormalUp);
    glutSpecialFunc(keySpecialDown);
    glutSpecialUpFunc(keySpecialUp);
}

void Input::Update()
{
    memoryNormalDown = 0;
    memoryNormalUp = 0;
    memorySpecialDown = 0;
    memorySpecialUp = 0;
}
