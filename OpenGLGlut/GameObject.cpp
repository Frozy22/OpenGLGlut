#include <iostream>
#include <Windows.h>
#include <glut.h>
#include <algorithm>
#include <vector>
#include <cstdarg>
#include "Utility.h"
#include "Input.h"
#include "GameObject.h"

using namespace Utility;

unsigned long GameObject::last_id;

std::vector<GameObject*> GameObject::gameObjects;

GameObject::GameObject(Vector2f position, float rotation, Vector2f scale, Color color, unsigned num, ...) {
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;
    this->color = color;

    if (num == 0)return;

    vertices.clear();

    va_list args;

    va_start(args, num);

    while (num--) {
        vertices.push_back(va_arg(args, Vector2f));
    }

    va_end(args);

    vertices.shrink_to_fit();
}

GameObject::GameObject(std::vector<Vector2f> vs, Color color, Vector2f position, float rotation, Vector2f scale) {
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;
    this->color = color;
    ReShape(vs);
    start();
}

void GameObject::start() {
    
}

void GameObject::update() {
    
}
// Transform
#if true
void GameObject::setParent(GameObject* parent){
    this->parent = parent;
}

void GameObject::removeParent(){
    parent = nullptr;
}

GameObject* GameObject::getParent(){
    return parent;
}

Vector2f GameObject::getGlobalPos(){
    if (parent != nullptr)
        return (parent->getGlobalPos() + position ) / UnitScale;
    else
        return (position) / UnitScale;
}

float GameObject::getGlobalRot(){
    if (parent != nullptr)
        return parent->getGlobalRot() + rotation;
    else
        return rotation;
}

Vector2f GameObject::getGlobalScl(){
    if (parent != nullptr)
        return parent->getGlobalScl() * scale;
    else
        return scale;
}
#endif

// Renderer
#if true
void GameObject::ReShape(unsigned num, Vector2f n, ...) {

    vertices.clear();
    if (num == 0) return;
    va_list args;

    va_start(args, num);

    while (num--) {
        vertices.push_back(va_arg(args, Vector2f));
    }

    va_end(args);

    vertices.shrink_to_fit();
}

void GameObject::ReShape(std::vector<Vector2f> vs) {

    vertices.clear();
    if (vs.size() == 0) return;
    for (int i = 0; i < vs.size(); i++) {
        vertices.push_back(vs[i]);
    }

    vertices.shrink_to_fit();
}

void GameObject::draw() {

    if (vertices.size() == 0) return;

    glColor4f(color.r, color.g, color.b, color.a);
    glBegin(GL_POLYGON);

    Vector2f scale = getGlobalScl();
    Vector2f position = getGlobalPos();
    Vector2f rotationX = Vector2f(1, 0).rotate(rotation);
    Vector2f rotationY = Vector2f(0, 1).rotate(rotation);
    Vector2f vertex;

    for (unsigned i = 0; i < vertices.size(); i++) {
        vertex = vertices[i];
        vertex = rotationX * vertex.x + rotationY * vertex.y;
        vertex *= scale;
        glVertex2f(position.x + vertex.x, position.y + vertex.y);
    }

    glEnd();
}
#endif

bool GameObject::operator==(GameObject obj) {
    return this->id == obj.id;
}

void GameObject::Destroy(GameObject obj) {
    delete &obj;
}

GameObject GameObject::Instantiate(GameObject* prefab) {
    prefab->id = last_id++;
    gameObjects.push_back(prefab);
    return *prefab;
}

void GameObject::Start()
{
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->start();
    }
}

void GameObject::Update()
{
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->update();
    }
}

void GameObject::Draw()
{
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->draw();
    }
}

GameObject::~GameObject() {
    
}
