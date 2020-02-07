#include <Windows.h>
#include <glut.h>
#include <cmath>
#include <vector>
#include "Utility.h"


namespace Utility {
    // ----------- Vector2f ----------- 
#if true
    Vector2f::Vector2f(float x, float y) {
        this->x = x;
        this->y = y;
    }

    Vector2f Vector2f::rotate(Vector2f point, float angle) {
        angle *= DegToRad;
        Vector2f rotated_point;
        rotated_point.x = point.x * cos(angle) - point.y * sin(angle);
        rotated_point.y = point.x * sin(angle) + point.y * cos(angle);
        return rotated_point;
    }

    Vector2f Vector2f::rotate(float angle) {
        angle *= DegToRad;
        Vector2f point = Vector2f(this->x,this->y);
        this->x = point.x * cos(angle) - point.y * sin(angle);
        this->y = point.x * sin(angle) + point.y * cos(angle);
        return *this;
    }

    Vector2f Vector2f::forward() {
        return normilize(*this);
    }
    Vector2f Vector2f::backward() {
        return normilize(*this) * -1;
    }

    Vector2f Vector2f::left() {
        Vector2f n = normilize(*this);
        return Vector2f(-n.y,n.x);
    }

    Vector2f Vector2f::right() {
        Vector2f n = normilize(*this);
        return Vector2f(n.y, -n.x);
    }

    float Vector2f::dot(Vector2f a, Vector2f b) {
        return a.x * b.x + a.y + b.y;
    }

    float Vector2f::angle() {
        return angle(*this);
    }

    float Vector2f::angle(Vector2f v) {
        return angle(v, Vector2f(1, 0));
    }

    float Vector2f::angle(Vector2f a, Vector2f b) {
        return acos(dot(a.normilize(), b.normilize()));
    }

    Vector2f Vector2f::normilize(Vector2f v) {
        return v.normilize();
    }

    Vector2f Vector2f::normilize() {
        return *this / length(*this);
    }

    float Vector2f::length(Vector2f v) {
        return v.length();
    }

    float Vector2f::length() {
        return sqrt(pow(this->x, 2) + pow(this->y, 2));
    }

    float Vector2f::distance(Vector2f a, Vector2f b) {
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    }

    // ÎÏÅÐÀÒÎÐÛ vec2
#if true

    Vector2f Vector2f::operator +=(Vector2f v) {
        *this = *this + v;
        return *this;
    }
    Vector2f Vector2f::operator-=(Vector2f v) {
        *this = *this - v;
        return *this;
    }
    Vector2f Vector2f::operator*=(Vector2f v) {
        *this = *this * v;
        return *this;
    }
    Vector2f Vector2f::operator/=(Vector2f v) {
        *this = *this / v;
        return *this;
    }
    Vector2f Vector2f::operator*=(float v) {
        *this = *this * v;
        return *this;
    }
    Vector2f Vector2f::operator/=(float v) {
        *this = *this / v;
        return *this;
    }
    Vector2f Vector2f::operator +(Vector2f v) {
        Vector2f r = *this;
        r.x += v.x;
        r.y += v.y;
        return r;
    }
    Vector2f Vector2f::operator-(Vector2f v) {
        this->x -= v.x;
        this->y -= v.y;
        return *this;
    }
    Vector2f Vector2f::operator*(Vector2f v) {
        Vector2f r = *this;
        r.x *= v.x;
        r.y *= v.y;
        return r;
    }
    Vector2f Vector2f::operator/(Vector2f v) {
        Vector2f r = *this;
        r.x /= v.x;
        r.y /= v.y;
        return r;
    }
    Vector2f Vector2f::operator*(float v) {
        Vector2f r = *this;
        r.x *= v;
        r.y *= v;
        return r;
    }
    Vector2f Vector2f::operator/(float v) {
        Vector2f r = *this;
        r.x /= v;
        r.y /= v;
        return r;
    }
    Vector2f Vector2f::operator=(Vector2f v) {
        this->x = v.x;
        this->y = v.y;
        return *this;
    }
#endif
#endif
    // ----------- Vector2f ----------- 

    // ----------- Color ----------- 
#if true
    Color::Color(float r, float g, float b, float a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }
    Color::Color(float c) {
        this->r = c;
        this->g = c;
        this->b = c;
        this->a = c;
    }

    // ÎÏÅÐÀÒÎÐÛ color
#if true

    Color Color::operator =(Color c) {
        this->r = c.r;
        this->g = c.g;
        this->b = c.b;
        this->a = c.a;
        return *this;
    }

#endif
#endif
    // ----------- Color ----------- 

    std::vector<Vector2f> generate_circle(float radius, float segments) {
        std::vector<Vector2f> vertices;
        vertices.push_back(Vector2f(0, 0));
        segments = 360 / segments;
        for (float angle = 0; angle <= 360; angle += segments) {
            vertices.push_back(Vector2f(cos(angle * 3.14 / 180) * radius, sin(angle * 3.14 / 180) * radius));
        }
        return vertices;
    }
}