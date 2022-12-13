#include "Train.h"

Train::Train()
{
	cout << "----------------------------------\n     Добавление поезда     \n----------------------------------" << endl << endl;
	try
	{
		setType(2);

		cout << "Введите название поезда = ";
		cin.ignore(256, '\n');
		getline(cin, name);
		if(name == "")
			throw (string)"Название не может быть пустым";

		cout << "Введите год выпуска поезда = ";
		cin >> this->year;
		if (!this->year || this->year < 0)
		{
			throw (string)"Год равен нулю или отрицателен";
		}

		cout << "Введите маршрут следования поезда = ";
		cin.ignore(256, '\n');
		getline(cin, route);
		if (route == "")
			throw (string)"Маршрут не может быть пустым";

		cout << "Введите количество вагонов = ";
		cin >> this->vagon;
		if (this->vagon < 0)
		{
			throw (string)"Количество вагонов не может быть отрицательным";
		}

		cout << "Введите объем перевозимого груза = ";
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

Train::Train(ifstream& fin)
{
	setType(2);
	fin.ignore(256, '\n');
	getline(fin, name);
	fin.ignore(256, '\n');
	getline(fin, route);
	fin >> this->year >> this->vagon >> this->volume;
}

Train::~Train()
{
	cout << "Был вызван деструктор класса Train" << endl;
	system("pause");
}

void Train::edit()
{
	try
	{
		int index;
		int iTmp;
		string sTmp;
		cout << "Выберите параметр для изменения:" << endl
			<< "[1] Название" << endl
			<< "[2] Год выпуска" << endl
			<< "[3] Маршрут" << endl
			<< "[4] Количество вагонов" << endl
			<< "[5] Объем перевозимого груза" << endl
			<< "Ваш выбор: ";
		cin >> index;
		if (index < 1 || index > 5)
		{
			throw (string)"Параметра с данным индексом не существует";
		}
		cout << "Исходное значение: ";
		switch (index)
		{
		case 1:

			cout << name << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"Название не может быть пустым";
			name = sTmp;
			break;

		case 2:

			cout << year << endl;
			cout << "Новое значение: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"Год равен нулю или отрицателен";
			}
			year = iTmp;
			break;

		case 3:

			cout << route << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"Маршрут не может быть пустым";
			route = sTmp;
			break;

		case 4:

			cout << vagon << endl;
			cout << "Новое значение: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"Количество вагонов не может быть отрицательным";
			}
			vagon = iTmp;
			break;

		case 5:

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

void Train::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->name << endl
		<< this->year << endl
		<< this->route << endl
		<< this->vagon << endl
		<< this->volume << endl;
}

void Train::print(ostream& out)
{
	out << "----------------------------------\n        Поезд        \n----------------------------------" << endl
		<< "Название : " << this->name << endl
		<< "Год выпуска : " << this->year << endl
		<< "Маршрут : " << this->route << endl
		<< "Количество вагонов : " << this->vagon << endl
		<< "Объем груза : " << this->volume << endl;
}
