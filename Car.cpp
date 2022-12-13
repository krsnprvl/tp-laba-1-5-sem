#include "Car.h"

Car::Car()
{
	cout << "----------------------------------\n     Добавление автомобиля     \n----------------------------------" << endl << endl;
	try
	{
		setType(3);

		cout << "Введите год выпуска автомобиля = ";
		cin >> this->year;
		if (!this->year || this->year < 0)
		{
			throw (string)"Год равен нулю или отрицателен";
		}

		cout << "Введите марку автомобиля = ";
		cin.ignore(256, '\n');
		getline(cin, brand);
		if (brand == "")
			throw (string)"Марка не может быть пустой";

		cout << "Введите модель автомобиля = ";
		getline(cin, model);
		if (model == "")
			throw (string)"Модель не может быть пустой";

		cout << "Введите город доставки = ";
		getline(cin, city);
		if (city == "")
			throw (string)"Город не может быть пустым";

		cout << "Введите время доставки = ";
		cin >> this->time;
		if (!this->time || this->time < 0)
		{
			throw (string)"Время равно нулю или отрицательно";
		}

		cout << "Введите объем груза = ";
		cin >> this->volume;
		if (!this->volume || this->volume < 0)
		{
			throw (string)"Объем равен нулю или отрицателен";
		}

		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}

Car::Car(ifstream& fin)
{
	setType(3);
	fin >> this->year >> this->time >> this->volume;
	fin.ignore(256, '\n');
	getline(fin, brand);
	fin.ignore(256, '\n');
	getline(fin, model);
	fin.ignore(256, '\n');
	getline(fin, city);
}

Car::~Car()
{
	cout << "Был вызван деструктор класса Car" << endl;
}

void Car::edit()
{
	try
	{
		int index;
		int iTmp;
		string sTmp;
		cout << "Выберите параметр для изменения:" << endl
			<< "[1] Год выпуска" << endl
			<< "[2] Марка" << endl
			<< "[3] Модель" << endl
			<< "[4] Город доставки" << endl
			<< "[5] Время доставки" << endl
			<< "[6] Объем груза" << endl
			<< "Ваш выбор: ";
		cin >> index;
		if (index < 1 || index > 6)
		{
			throw (string)"Параметра с данным индексом не существует";
		}
		cout << "Исходное значение: ";
		switch (index)
		{
		case 1:

			cout << year << endl;
			cout << "Новое значение: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"Год равен нулю или отрицателен";
			}
			year = iTmp;
			break;

		case 2:

			cout << brand << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"Марка не может быть пустой";
			brand = sTmp;
			break;

		case 3:

			cout << model << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"Модель не может быть пустой";
			model = sTmp;
			break;

		case 4:

			cout << city << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"Город не может быть пустым";
			city = sTmp;
			break;

		case 5:

			cout << time << endl;
			cout << "Новое значение: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"Время равно нулю или отрицательно";
			}
			time = iTmp;
			break;

		case 6:

			cout << volume << endl;
			cout << "Новое значение: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"Объем равен нулю или отрицателен";
			}
			volume = iTmp;
			break;

		default:
			break;
		}
		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}

void Car::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->year << endl
		<< this->brand << endl
		<< this->model << endl
		<< this->city << endl
		<< this->time << endl
		<< this->volume << endl;
}

void Car::print(ostream& out)
{
	out << "----------------------------------\n        Автомобиль        \n----------------------------------" << endl
		<< "Год выпуска : " << this->year << endl
		<< "Марка : " << this->brand << endl
		<< "Модель : " << this->model << endl
		<< "Город доставки : " << this->city << endl
		<< "Время доставки : " << this->time << endl
		<< "Объем груза : " << this->volume << endl;
}
