#pragma once

namespace Utility {

#define PI 3.1415926535
#define DegToRad 0.0174532925
#define RadToDeg 57.2957795130
#define UnitScale 100.0

    struct Vector2f {
        float x = 0;
        float y = 0;
        Vector2f(float x = 0, float y = 0);

        static Vector2f rotate(Vector2f point, float angle);

        Vector2f rotate(float angle);

        Vector2f forward();

        Vector2f backward();

        Vector2f left();

        Vector2f right();

        static float dot(Vector2f a, Vector2f b); // ��������� ������������ ��������

        float angle(); // ����������� �������

        static float angle(Vector2f v); // ����������� �������

        static float angle(Vector2f a, Vector2f b); // ���� ����� ���������

        static Vector2f normilize(Vector2f v); // ��������������� ������

        Vector2f normilize(); // ��������������� ������

        static float length(Vector2f v); // ����� �������
        float length(); // ����� �������

        static float distance(Vector2f a, Vector2f b); // ���������� ����� ���������

        Vector2f operator +=(Vector2f v);
        Vector2f operator -=(Vector2f v);
        Vector2f operator *=(Vector2f v);
        Vector2f operator /=(Vector2f v);
        Vector2f operator *=(float v);
        Vector2f operator /=(float v);
        Vector2f operator +(Vector2f v);
        Vector2f operator -(Vector2f v);
        Vector2f operator *(Vector2f v);
        Vector2f operator /(Vector2f v);
        Vector2f operator *(float v);
        Vector2f operator /(float v);
        Vector2f operator =(Vector2f v);
    };

    struct Color {
        float r = 0, g = 0, b = 0, a = 0;
        Color(float r, float g, float b, float a = 1);
        Color(float c = 0);
        Color operator =(Color c);
    };

    std::vector<Vector2f> generate_circle(float radius, float segments); // ��������� ����� � �������� � ����������� ���������
}
