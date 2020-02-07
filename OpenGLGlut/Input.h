#pragma once

class Input
{
private:
    static unsigned int memoryNormal;
    static unsigned int memoryNormalDown;
    static unsigned int memoryNormalUp;
    static unsigned int memorySpecial;
    static unsigned int memorySpecialDown;
    static unsigned int memorySpecialUp;

    static void keyNormalDown(unsigned char key, int x, int y);
    static void keyNormalUp(unsigned char key, int x, int y);
    static void keySpecialDown(int key, int x, int y);
    static void keySpecialUp(int key, int x, int y);
public:
    static void Init(); // ������������� ����������
    static void Update(); // ������� ���������� ����������
    static bool getNormalKey(unsigned char key); // ����������� ������� ������
    static bool getNormalDown(unsigned char key); // ����������� ������� ������
    static bool getNormalUp(unsigned char key); // ����������� ������� ��������
    static bool getSpecialKey(unsigned char key); // ����������� ������� ������
    static bool getSpecialDown(unsigned char key); // ����������� ������� ������
    static bool getSpecialUp(unsigned char key); // ����������� ������� ��������
};
