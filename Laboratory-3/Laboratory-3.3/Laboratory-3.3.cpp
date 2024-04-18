#include <iostream>                    
#include <fstream> 
#include <string> 
#include <windows.h>
using namespace std;

struct date {
	unsigned int MonthDay : 6;    // 0..31  (6 bits)
	unsigned int Month : 5;    // 0..12  (5 bits)
	unsigned int Year : 12;    // 0..4095 (12 bits)
};
enum mf { MALE, FEMALE };


struct citizen {
	string name = "";
	string surname = "";
	string address = "";

	mf sex;
	date DOB;
};

citizen inputCitizen()
{
	citizen c;
	cout << "Введите имя: ";
	cin >> c.name;
	cout << "Введите фамилию: ";
	cin >> c.surname;
	cout << "Введите адрес: ";
	cin >> c.address;
	cout << "Введите пол(1 - мужской, 2 - женский): ";
	unsigned int n = 0;
	cin >> n;
	c.sex = static_cast<mf>(n);
	cout << "Введите день месяца рождения: ";
	cin >> n;
	c.DOB.MonthDay = n;
	cout << "Введите месяц рождения: ";
	cin >> n;
	c.DOB.Month = n;
	cout << "Введите год рождения: ";
	cin >> n;
	c.DOB.Year = n;
	return c;
}

void outputCitizen(citizen c) {
	cout << "Имя: " << c.name << endl;
	cout << "Фамилия: " << c.surname << endl;
	cout << "Адрес: " << c.address << endl;
	switch (c.sex)
	{
	case MALE:
	{cout << "Пол: Мужской" << endl; break; }
	case FEMALE:
	{cout << "Пол: Женский" << endl; break; }
	}
	cout << "День рождения: " << c.DOB.MonthDay << "." << c.DOB.Month << "." << c.DOB.Year << endl;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	citizen citizens[500];
	int choice = 0, citizensCount = 0;
	bool readElements = false;
	do
	{
		cout << "Введите:" << endl;
		cout << "1 - для записи с клавиатуры" << endl;
		cout << "2 - для вывода на экран" << endl;
		cout << "3 - для поиска по фамилии" << endl;
		cout << "4 - для удаления горожанина по фамилии" << endl;
		cout << "5 - для поиска по году рождения" << endl;
		cout << "6 - для выхода" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Введите количество горожан: ";
			cin >> citizensCount;
			for (int i = 0; i < citizensCount; ++i)
			{
				citizens[i] = inputCitizen();
			}
			readElements = true;
		}
		break;
		case 2:
			if (readElements)
			{
				cout << "Количество горожан: " << citizensCount << endl;
				for (int i = 0; i < citizensCount; ++i)
				{
					outputCitizen(citizens[i]);
				}
			}
			else { cout << "Нет прочитанных данных" << endl; }
			break;

		case 3:
			if (readElements) {
				string surname;
				cout << "Ввод фамилии для поиска:" << endl;
				cin >> surname;
				{
					int num;
					bool is = true;
					for (int i = 0; i < citizensCount; ++i)
					{
						if (citizens[i].surname == surname)
						{
							num = i;
							break;
							is = false;
						}
					}
					if (is)
					{
						cout << "Горожанин не найден" << endl;
					}
					else
					{
						outputCitizen(citizens[num]);
					}
				}
			}
			else { cout << "Нет прочитанных данных" << endl; }
			break;

		case 4:
			if (readElements) {
				string surname;
				cout << "Ввод фамилии для удаления:" << endl;
				cin >> surname;
				{
					int num;
					bool is = true;
					for (int i = 0; i < citizensCount; ++i)
					{
						if (citizens[i].surname == surname)
						{
							num = i;
							break;
							is = false;
						}
					}
					if (is)
					{
						cout << "Горожанин не найден" << endl;
					}
					else
					{
						citizensCount--;
						for (int i = num; i < citizensCount; ++i)
						{
							citizens[i] = citizens[i + 1];
						}
					}
				}
			}
			else { cout << "Нет прочитанных данных" << endl; }
			break;

		case 5:
			if (readElements) {
				string surname;
				cout << "Ввод фамилии для поиска:" << endl;
				cin >> surname;
				{
					int num;
					bool is = true;
					for (int i = 0; i < citizensCount; ++i)
					{
						if (citizens[i].surname == surname)
						{
							num = i;
							break;
							is = false;
						}
					}
					if (is)
					{
						cout << "Горожанин не найден" << endl;
					}
					else
					{
						outputCitizen(citizens[num]);
					}
				}
			}
			else { cout << "Нет прочитанных данных" << endl; }
			break;

		case 6:
			if (readElements) {
				unsigned int year;
				cout << "Ввод года для удаления:" << endl;
				cin >> year;
				{
					bool is = true;
					for (int i = 0; i < citizensCount; ++i)
					{
						if (citizens[i].DOB.Year == year)
						{
							outputCitizen(citizens[i]);
							is = false;
						}
					}
					if (is)
					{
						cout << "Горожане не найдены" << endl;
					}
				}
			}
			else { cout << "Нет прочитанных данных" << endl; }
			break;

		}
	} while (choice != 6);
}
