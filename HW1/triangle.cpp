#include <iostream>
#include <cmath>

using namespace std;

// Функция для вычисления расстояния между двумя точками
float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Функция для вычисления площади треугольника по координатам вершин
float Area(float x1, float y1, float x2, float y2, float x3, float y3) {
    return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
}

// Функция для вычисления периметра треугольника
float Perimeter(float a, float b, float c) {
    return a + b + c;
}

int main() {
    // Объявление переменных для координат точек
    float x1, y1, x2, y2, x3, y3;

    // Ввод координат точек
    cout << "Введите координаты первой точки (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Введите координаты второй точки (x2 y2): ";
    cin >> x2 >> y2;

    cout << "Введите координаты третьей точки (x3 y3): ";
    cin >> x3 >> y3;

    // Вычисление длины сторон треугольника
    float a = distance(x1, y1, x2, y2);
    float b = distance(x2, y2, x3, y3);
    float c = distance(x3, y3, x1, y1);

    // Вычисление площади и периметра
    float area = Area(x1, y1, x2, y2, x3, y3);
    float perimeter = (a, b, c);

    // Вывод результатов
    cout << "Площадь треугольника: " << area << endl;
    cout << "Периметр треугольника: " << perimeter << endl;

    return 0;
}
