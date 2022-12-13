#include "Airplane.h"

Airplane::Airplane()
{
	cout << "----------------------------------\n   Добавление самолета\n----------------------------------" << endl << endl;
	try
	{
		setType(1);
		cin.ignore(256, '\n');
		cout << "Введите тип самолета = ";
		getline(cin, this->type);
		if (type == "")
			throw (string)"Тип не может быть пустым";
		setError(false);

		cout << "Введите наименование самолета = ";
		getline(cin, this->name);
		if (name == "")
			throw (string)"Наименование не может быть пустым";
		setError(false);

		cout << "Введите объем перевозимого груза = ";
		cin >> this->volume;
		if (!this->volume || this->volume < 0)
		{
			throw (string)"Объем равен нулю или отрицателен";
		}

		cout << "Введите габариты самолета = ";
		cin >> this->size;
		if (!this->size || this->size < 0)
		{
			throw (string)"Габариты равны нулю или отрицательны";
		}

		cout << "Какие города посещает самолет = ";
		cin.ignore(256, '\n');
		getline(cin, this->city);
		if (city == "")
			throw (string)"Наименование не может быть пустым";

		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}

Airplane::Airplane(ifstream& fin)
{
	setType(1);
	fin >> this->volume  >> this->size;
	fin.ignore(256, '\n');
	getline(fin, type);
	fin.ignore(256, '\n');
	getline(fin, name);
	fin.ignore(256, '\n');
	getline(fin, city);
}

Airplane::~Airplane()
{
	cout << "Был вызван деструктор класса Airplane" << endl;
	system("pause");
}

void Airplane::edit()
{
	try
	{
		int index;
		int iTmp;
		string sTmp;
		cout << "Выберите параметр для изменения:" << endl
			<< "[1] Тип" << endl
			<< "[2] Наименование" << endl
			<< "[3] Объем груза" << endl
			<< "[4] Габариты" << endl
			<< "[5] Города" << endl
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

			cout << type << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"Тип не может быть пустым";
			type = sTmp;
			break;

		case 2:

			cout << name << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"Наименование не может быть пустым";
			name = sTmp;
			break;

		case 3:

			cout << volume << endl;
			cout << "Новое значение: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"Объем равен нулю или отрицателен";
			}
			volume = iTmp;
			break;

		case 4:

			cout << size << endl;
			cout << "Новое значение: ";
			cin >> iTmp;
			if (iTmp < 0)
			{
				throw (string)"Габариты равны нулю или отрицательны";
			}
			size = iTmp;
			break;

		case 5:

			cout << city << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"Наименование не может быть пустым";
			city = sTmp;
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

void Airplane::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->type << endl
		<< this->name << endl
		<< this->volume << endl
		<< this->size << endl
		<< this->city << endl;
}

void Airplane::print(ostream& out)
{
	out << "----------------------------------\n    Самолет    \n----------------------------------" << endl
		<< "Тип самолета : " << type << endl
		<< "Наименование самолета : " << name << endl
		<< "Объем перевозимого груза : " << volume << endl
		<< "Габариты : " << size << endl
		<< "Города : " << city << endl;
}