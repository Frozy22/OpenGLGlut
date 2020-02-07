#pragma once

using namespace Utility;


class GameObject
{

private:
    static unsigned long last_id; // Последний свободный ID
    unsigned long id; // ID объекта

protected:
    static std::vector<GameObject*> gameObjects; // Список всех объектов
    GameObject* parent = nullptr; // Родитель объекта
    std::vector<Vector2f> vertices; // Форма объекта

public:
    Color color = Color(1.0f); // Цвет объекта

    Vector2f position = Vector2f(0.0f, 0.0f); // Позиция объекта
    float rotation = 0.0f; // Угол поворота объекта
    Vector2f scale = Vector2f(1.0f, 1.0f); // Масштаб объекта

    GameObject(Vector2f position = Vector2f(0.0f, 0.0f), float rotation = 0.0f, Vector2f scale = Vector2f(1.0f, 1.0f), Color color = Color(1), unsigned num = 0, ...);
    GameObject(std::vector<Vector2f> vs, Color color = Color(1), Vector2f position = Vector2f(0.0f, 0.0f), float rotation = 0.0f, Vector2f scale = Vector2f(1.0f, 1.0f));

    virtual void start(); // Функция старта
    virtual void update(); // Функция обновления
    virtual void draw(); // Функция отрисовки

    static void Destroy(GameObject obj); // Уничтожение объекта

    static GameObject Instantiate(GameObject* prefab); // Регистрация объекта

    static void Start(); // Вызов функции старта у всех обхектов
    static void Update(); // Вызов функции обновления у всех обхектов
    static void Draw(); // Вызов функции отрисовки у всех обхектов

    void setParent(GameObject* parent); // Назначение родителя
    void removeParent(); // Удаление родителя
    GameObject* getParent(); // Возвращение родителя

    Vector2f getGlobalPos(); // Возвращение позиции учитывая позицию родителя
    float getGlobalRot(); // Возвращение поворота учитывая поворот родителя
    Vector2f getGlobalScl(); // Возвращение масштаба учитывая масштаб родителя

    void ReShape(unsigned num, Vector2f n, ...); // Изменение формы
    void ReShape(std::vector<Vector2f> vs); // Изменение формы

    bool operator ==(GameObject obj);

    ~GameObject();
};

