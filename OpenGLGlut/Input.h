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
    static void Init(); // Инициализация управления
    static void Update(); // Функция обновления управления
    static bool getNormalKey(unsigned char key); // Стандартная клавиша зажата
    static bool getNormalDown(unsigned char key); // Стандартная клавиша нажата
    static bool getNormalUp(unsigned char key); // Стандартная клавиша отпущена
    static bool getSpecialKey(unsigned char key); // Специальная клавиша зажата
    static bool getSpecialDown(unsigned char key); // Специальная клавиша нажата
    static bool getSpecialUp(unsigned char key); // Специальная клавиша отпущена
};
