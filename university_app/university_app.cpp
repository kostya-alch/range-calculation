// university_app.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <iomanip>  // библиотечка для форматирования таблицы

const int num = 105; // мой вариант в журнале

double numerator(double x) {
	return ((log((1 - num) / cos(x + num)) / log(21))); // функция первой части формулы
}

double denominator(double x) {
	return ((sin(x) / num)); // функция второй части формулы	
}

double getValue() { // функция обработки ошибки если число введено неверно
	while (true) {
		double a;
		std::cin >> a;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Введено некорректное значение\n";
		}
		else {
			std::cin.ignore(32767, '\n');
			return a;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");

	double xend = 0;
	double xstart = 0;
	double dx = 0;

	std::cout << "Для ввода вещественных чисел используйте точку в качестве разделителя" << std::endl << std::endl;
	std::cout << "Введите начальное значение x: " << std::endl;
	xstart = getValue();

	std::cout << "Введите конечное значение x: " << std::endl;
	xend = getValue();

	std::cout << "Введите deltaX: " << std::endl;
	dx = getValue();

	std::cout << std::endl << std::endl;

	int w1 = std::max(int(log10(abs(xstart)) + 5), int(log10(abs(xend)) + 5)); // вычисление ширины первого столбца для вывода в таблицу
	int w2 = 15; // больше вводим не можем из-за вещественного числа
	int w3 = 90; // столбец с ошибками

	std::cout << std::left << std::setw(w1) << "X" << std::setw(w2) << "Результат" << std::setw(w3) << "Сообщение об ошибке" << std::endl;

	if (dx == 0) // две проверки шага переменной
		std::cout << std::setw(w1 + w2) << " " << std::setw(w3) << "Шаг изменения переменной равен нулю" << std::endl;

	else if (dx <= 0)
		std::cout << std::setw(w1 + w2) << " " << std::setw(w3) << "Знак шага изменения переменной направлен в противоположенную сторону от конечного значения Х" << std::endl;

	else if (dx > 0) //проверка куда пойдет вычисление
		for (double i = xstart; i <= xend; i += dx)
		{
			if (cos(i - num) == 0)
				std::cout << std::setw(w1) << i << std::setw(w2) << std::setw(w3) << "Ошибка деления на ноль" << std::endl;

			else if (((1 - num) / cos(i + num)) <= 0)
				std::cout << std::setw(w1) << i << std::setw(w2) << " " << std::setw(w3) << "Ошибка взятия логарифма от неположительного числа" << std::endl;

			else std::cout << std::setw(w1) << i << std::setw(w2) << std::min(numerator(i), denominator(i)) << std::endl;
		}
	else
		for (double i = xstart; i >= xend; i += dx)
		{
			if (cos(i - num) == 0)
				std::cout << std::setw(w1) << i << std::setw(w2) << std::setw(w3) << "Ошибка деления на ноль" << std::endl;

			else if (((1 - num) / cos(i + num)) <= 0)
				std::cout << std::setw(w1) << i << std::setw(w2) << " " << std::setw(w3) << "Ошибка взятия логарифма от неположительного числа" << std::endl;

			else std::cout << std::setw(w1) << i << std::setw(w2) << std::min(numerator(i), denominator(i)) << std::endl;
		}
	system("pause");
	return 0;
}


