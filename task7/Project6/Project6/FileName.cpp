#include <iostream>
#include <cmath>

using namespace std;

// Ежемесячный платеж по ипотеке
struct MyStruct {
	static double mortgagePayment(double loanAmount, double annualRatePercent, int years)
	{
		if (annualRatePercent == 0.0)
		{
			return loanAmount / (years * 12);
		}
		double monthlyRate = annualRatePercent / 100.0 / 12.0;
		double totalMonths = years * 12;
		double ratio = pow(1.0 + monthlyRate, totalMonths);
		return loanAmount * (monthlyRate * ratio) / (ratio - 1.0);
	}

	// Цена за квадратный метр

	static double pricePerSquareMetr(double totalPrice, double area)
	{
		if (area == 0)
		{
			throw exception("Деление на ноль");
		}
		return totalPrice / area;
	}

	// Стоимость аренды в пересчете на день 

	static double rentCostPerDay(double monthlyRent)
	{
		if (monthlyRent < 0)
		{
			throw exception("Вам платят за ипотеку?");
		}
		return monthlyRent / 30.0;
	}

	// Площадь помещения по длине и ширине

	static double areaFromDimensions(double length, double width)
	{
		if (length <= 0 || width <= 0)
		{

			throw invalid_argument("У вас квартира в минус ушла?");
		}
		return length * width;
	}
};
int main()
{
	setlocale(0, "");
	double apartmentPrice{};
	double downPayment{};
	cout << "Введите стоимость квартиры и первоначальный взнос: " << endl;
	cin >> apartmentPrice;
	cin >> downPayment;
	double interestRate{};
	int creditYears{};
	double creditSum = apartmentPrice - downPayment;
	cout << endl << "Введите годовую ставку ипотеки и на сколько лет: ";
	cin >> interestRate;
	cin >> creditYears;


	double roomWidth{};
	double roomLength{};
	double rentPrice{};

	cout << "Введите длинну и ширину комнаты: ";
	cin >> roomLength;
	cin >> roomWidth;
	double roomArea = MyStruct::areaFromDimensions(roomLength, roomWidth);
	cout << "Площадь комнаты (" << roomLength << "x" << roomWidth << "): "
		<< roomArea << "кв.м" << endl;

	double totalArea{};
	cout << endl << "Введите площадь квартиры: ";
	cin >> totalArea;
	double pricePerMeter = MyStruct::pricePerSquareMetr(apartmentPrice, totalArea);
	cout << "Цена за квадратный метр = " << pricePerMeter << endl;

	double payment = MyStruct::mortgagePayment(creditSum, interestRate, creditYears);
	cout << "Ипотека (Кредит: " << creditSum << ", Ставка: " << interestRate << "%, Срок: " << creditYears << " лет): "
		<< payment << " руб./мес" << endl;

	double rentDay = MyStruct::rentCostPerDay(payment);
	cout << "Плата в день = " << rentDay << endl;

	getchar();
	return 0;
}
