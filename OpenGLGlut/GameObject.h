#pragma once

using namespace Utility;


class GameObject
{

private:
    static unsigned long last_id; // ��������� ��������� ID
    unsigned long id; // ID �������

protected:
    static std::vector<GameObject*> gameObjects; // ������ ���� ��������
    GameObject* parent = nullptr; // �������� �������
    std::vector<Vector2f> vertices; // ����� �������

public:
    Color color = Color(1.0f); // ���� �������

    Vector2f position = Vector2f(0.0f, 0.0f); // ������� �������
    float rotation = 0.0f; // ���� �������� �������
    Vector2f scale = Vector2f(1.0f, 1.0f); // ������� �������

    GameObject(Vector2f position = Vector2f(0.0f, 0.0f), float rotation = 0.0f, Vector2f scale = Vector2f(1.0f, 1.0f), Color color = Color(1), unsigned num = 0, ...);
    GameObject(std::vector<Vector2f> vs, Color color = Color(1), Vector2f position = Vector2f(0.0f, 0.0f), float rotation = 0.0f, Vector2f scale = Vector2f(1.0f, 1.0f));

    virtual void start(); // ������� ������
    virtual void update(); // ������� ����������
    virtual void draw(); // ������� ���������

    static void Destroy(GameObject obj); // ����������� �������

    static GameObject Instantiate(GameObject* prefab); // ����������� �������

    static void Start(); // ����� ������� ������ � ���� ��������
    static void Update(); // ����� ������� ���������� � ���� ��������
    static void Draw(); // ����� ������� ��������� � ���� ��������

    void setParent(GameObject* parent); // ���������� ��������
    void removeParent(); // �������� ��������
    GameObject* getParent(); // ����������� ��������

    Vector2f getGlobalPos(); // ����������� ������� �������� ������� ��������
    float getGlobalRot(); // ����������� �������� �������� ������� ��������
    Vector2f getGlobalScl(); // ����������� �������� �������� ������� ��������

    void ReShape(unsigned num, Vector2f n, ...); // ��������� �����
    void ReShape(std::vector<Vector2f> vs); // ��������� �����

    bool operator ==(GameObject obj);

    ~GameObject();
};

