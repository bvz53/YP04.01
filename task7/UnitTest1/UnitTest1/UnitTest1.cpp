#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "H:\Project1\Project1\FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{
	TEST_CLASS(MyStructTests)
	{
	public:



		TEST_METHOD(MortgagePayment_Positive_Standard)
		{
			double loan = 1000000.0;
			double rate = 12.0;
			int years = 1;
			double expected = 88848.79;

			double actual = MyStruct::mortgagePayment(loan, rate, years);
			Assert::AreEqual(expected, actual, 0.1, L"Ошибка в стандартном расчете ипотеки");
		}

		TEST_METHOD(MortgagePayment_Negative_ZeroYears)
		{
			double loan = 1000000.0;
			double rate = 10.0;
			int years = 0;

			double actual = MyStruct::mortgagePayment(loan, rate, years);
			Assert::IsTrue(std::isinf(actual), L"При 0 лет должна возвращаться бесконечность");
		}



		TEST_METHOD(PricePerMetr_Positive_Simple)
		{

			double price = 5000000.0;
			double area = 50.0;
			double expected = 100000.0;

			Assert::AreEqual(expected, MyStruct::pricePerSquareMetr(price, area), 0.01);
		}

		TEST_METHOD(PricePerMetr_Negative_ZeroArea)
		{

			double price = 100000.0;
			double area = 0.0;

			double actual = MyStruct::pricePerSquareMetr(price, area);
			Assert::IsTrue(std::isinf(actual), L"Цена за м2 при площади 0 должна быть бесконечностью");
		}
	};
}
