#include <iostream>
#include <cmath>

const double PI = 3.14;
///<summary>
///Функция поиска площади круга.
///</summary>
/// <param name="radius">Радиус круга</param>
/// <returns>Площадь круга или -1 при ошибке</returns>
static double calculateCircleArea(double radius)
{
	if (radius <= 0) // +1 к η2
	{
		return -1; // +1 r η1
	}


	double area = PI * pow(radius, 2);// +1 r η1
	return area;// +1 r η1
}

int main()
{
	setlocale(LC_ALL, "Russian");


	double area1 = calculateCircleArea(5.0);
	std::cout << "Площадь круга: " << area1 << std::endl;
	return 0;
}
