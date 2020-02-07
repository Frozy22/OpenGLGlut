#include "Header.h"
#include "Utility.h"
#include "Input.h"
#include "GameObject.h"
#include "Triangle.h"

using namespace Utility;

int Height = 600; // Ширина окна
int Width = 600; // Высота окна
Vector2f camera_pos = Vector2f(0,0); // Позиция камеры
int Far = 10; // Глубина экрана

void update(); // Обновление
void draw(); // Отрисовка
void Reshape(GLint w, GLint h); // Реагирование на изменение окна

int main(int argc, char* argv[]) {
    // Инициализация окна //--
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Win32 GLUT");
    glutInitWindowSize(Width, Height);
    // Инициализация окна --//

    glutReshapeFunc(Reshape); // Функция изменения окна
    glutDisplayFunc(draw); // Функция отрисовки

    Input::Init(); // Инициализация управления

    glutIdleFunc(update); // Функция обновления

    glClearColor(0, 0, 0, 1.0); // Цвет экрана при очистке
    Triangle obj(Vector2f(0, 0), 0, Vector2f(100, 100)); // Создание объекта
    GameObject::Instantiate(&obj); // Регистрация объекта

    GameObject::Start(); // Вызов функции старта у всех обхектов
    glutMainLoop(); // Передача управления под библиотеку glut
}

void update() {
    GameObject::Update(); // Вызов функции обновления у всех обхектов
    Input::Update(); // Вызов функции обновления управления
    glutPostRedisplay(); // Вызов отрисовки
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT); // Очищение
    glTranslatef(-camera_pos.x,-camera_pos.y,0); // Перемещение на позицию камеры
    GameObject::Draw(); // Вызов функции отрисовки у всех обхектов
    glFlush(); // Вывод из буффера
    glTranslatef(camera_pos.x, camera_pos.y, 0); // Возвращение на нулевую позицию
}

void Reshape(GLint w, GLint h) {
    Width = w; // Обновление ширины экрана
    Height = h;// Обновление высоты экрана

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-Width / 2, Width / 2, -Height / 2, Height / 2, -Far / 2, Far / 2); // Выставление границ проекции

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
