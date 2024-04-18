#include <iostream>                    
#include <fstream> 
#include <string> 
#include <windows.h>
using namespace std;

union number {
	short s;
	int i;
	long l;
	long long ll;
};

struct train {
	number num;
	string destination = "";
	string travelDays = "";
	string arrival = "";
	string departure = "";

};

train inputTrain()
{
	train c;
	cout << "Введите номер поезда: ";
	cin >> c.num.ll;
	cout << "Введите пункт назначения: ";
	cin >> c.destination;
	cout << "Введите дни следования: ";
	cin.ignore();
	getline(cin, c.travelDays);
	//cin >> c.travelDays;
	cout << "Введите время прибытия: ";
	cin >> c.arrival;
	cout << "Введите время отправления: ";
	cin >> c.departure;

	return c;
}

void outputTrain(train c) {
	cout << "Номер поезда: " << c.num.ll << endl;
	cout << "Пункт назначения: " << c.destination << endl;
	cout << "Дни следования: " << c.travelDays << endl;
	cout << "Время прибытия: " << c.arrival << endl;
	cout << "Время отправления: " << c.departure << endl;
}

train inputfTrain(ifstream& in) {
	train c;
	in >> c.num.ll;
	in >> c.destination;
	in.ignore();
	getline(in, c.travelDays);
	//in >> c.travelDays;
	in >> c.arrival;
	in >> c.departure;
	return c;
}

void outputfTrain(ofstream& out, train c) {
	out << "Номер поезда: " << c.num.ll << endl;
	out << "Пункт назначения: " << c.destination << endl;
	out << "Дни следования: " << c.travelDays << endl;
	out << "Время прибытия: " << c.arrival << endl;
	out << "Время отправления: " << c.departure << endl;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	train trains[500];
	int choice = 0, trainsCount = 0;
	bool readElements = false;
	do
	{
		cout << "Введите:" << endl;
		cout << "1 - для ввода с клавиатуры" << endl;
		cout << "2 - для вывода на экран" << endl;
		cout << "3 - для поиска по фамилии" << endl;
		cout << "4 - для ввода с файла" << endl;
		cout << "5 - для вывода в файл" << endl;
		cout << "6 - для выхода" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Введите количество поездов: ";
			cin >> trainsCount;
			for (int i = 0; i < trainsCount; ++i)
			{
				trains[i] = inputTrain();
			}
			readElements = true;
		}
		break;
		case 2:
			if (readElements)
			{
				cout << "Количество поездов: " << trainsCount << endl;
				for (int i = 0; i < trainsCount; ++i)
				{
					outputTrain(trains[i]);
				}
			}
			else { cout << "Нет прочитанных данных" << endl; }
			break;

		case 3:
			if (readElements) {
				string destination;
				cout << "Ввод фамилии для поиска:" << endl;
				cin >> destination;
				{
					int num;
					bool is = true;
					for (int i = 0; i < trainsCount; ++i)
					{
						if (trains[i].destination == destination)
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
						outputTrain(trains[num]);
					}
				}
			}
			else { cout << "Нет прочитанных данных" << endl; }
			break;

		case 4:
		{
			ifstream in("save.txt");
			in >> trainsCount;
			for (int i = 0; i < trainsCount; ++i)
			{
				trains[i] = inputfTrain(in);
			}
			readElements = true;
			in.close();
		}
		break;

		case 5:
			if (readElements) {
				ofstream out("save.txt");
				out << "Количество поездов: " << trainsCount << endl;
				for (int i = 0; i < trainsCount; ++i)
				{
					outputfTrain(out, trains[i]);
				}
				out.close();
			}
			else { cout << "Нет прочитанных данных" << endl; }
			break;

		}
	} while (choice != 6);
}
