#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14;

class AreaCalculator {
private:
    double lastArea;

public:
    AreaCalculator() : lastArea(0) {}

    double circleArea(double radius) {
        lastArea = PI * radius * radius;
        return lastArea;
    }

    double rectangleArea(double length, double width) {
        lastArea = length * width;
        return lastArea;
    }

    double triangleArea(double base, double height) {
        lastArea = 0.5 * base * height;
        return lastArea;
    }

    double getLastArea() {
        return lastArea;
    }

    void showLastArea() {
        cout << lastArea << endl;
    }
};

int main() {
    setlocale(0, "");

    AreaCalculator calc;

    cout << "    КАЛЬКУЛЯТОР ПЛОЩАДЕЙ ФИГУР" << endl;

    cout << "\n--- Круг ---" << endl;
    double radius = 5;
    cout << "Радиус: " << radius << endl;
    cout << "Площадь круга: " << calc.circleArea(radius) << endl;

    cout << "\n--- Прямоугольник ---" << endl;
    double length = 10, width = 4;
    cout << "Длина: " << length << ", Ширина: " << width << endl;
    cout << "Площадь прямоугольника: " << calc.rectangleArea(length, width) << endl;

    cout << "\n--- Треугольник ---" << endl;
    double base = 6, height = 8;
    cout << "Основание: " << base << ", Высота: " << height << endl;
    cout << "Площадь треугольника: " << calc.triangleArea(base, height) << endl;

    cout << "\n--- Последнее значение ---" << endl;
    cout << "getLastArea() вернул: " << calc.getLastArea() << endl;

    cout << "    ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ" << endl;

    cout << "\nВычисляем площадь круга с радиусом 3..." << endl;
    calc.circleArea(3);
    calc.showLastArea();

    cout << "\nВычисляем площадь квадрата 7x7..." << endl;
    calc.rectangleArea(7, 7);
    calc.showLastArea();

    getchar();
    return 0;
}
