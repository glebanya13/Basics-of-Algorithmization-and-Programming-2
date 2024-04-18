#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

// Структура TRAIN
struct TRAIN {
    string destination; // Название пункта назначения
    int trainNumber;    // Номер поезда
    string departureTime; // Время отправления
};

// Функция для сравнения времени
bool isTimeLater(const string& time1, const string& time2) {
    // Разбиваем строку времени на часы и минуты
    int hour1 = stoi(time1.substr(0, 2));
    int minute1 = stoi(time1.substr(3, 2));
    int hour2 = stoi(time2.substr(0, 2));
    int minute2 = stoi(time2.substr(3, 2));

    // Сравниваем часы
    if (hour1 > hour2) {
        return true;
    }
    else if (hour1 < hour2) {
        return false;
    }

    // Если часы одинаковые, сравниваем минуты
    return minute1 > minute2;
}


// Функция для сравнения по названию пункта назначения (для сортировки)
bool compareDestinations(const TRAIN& a, const TRAIN& b) {
    return a.destination < b.destination;
}

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    TRAIN trains[8]; // Массив поездов
    string currentTime; // Введенное с клавиатуры время

    // Ввод данных о поездах
    cout << "Введите данные о поездах:\n";
    for (int i = 0; i < 8; ++i) {
        cout << "Поезд " << i + 1 << ":\n";
        cout << "Название пункта назначения: ";
        cin >> trains[i].destination;
        cout << "Номер поезда: ";
        cin >> trains[i].trainNumber;
        cout << "Время отправления (в формате ЧЧ:ММ): ";
        cin >> trains[i].departureTime;
    }

    // Сортировка по названию пункта назначения
    sort(trains, trains + 8, compareDestinations);

    // Ввод времени для фильтрации
    cout << "\nВведите время, после которого нужно найти поезда (в формате ЧЧ:ММ): ";
    cin >> currentTime;

    bool found = false; // Флаг, указывающий на наличие найденных поездов

    // Вывод информации о поездах, отправляющихся после введенного времени
    cout << "\nПоезда, отправляющиеся после " << currentTime << ":\n";
    for (int i = 0; i < 8; ++i) {
        if (isTimeLater(trains[i].departureTime, currentTime)) {
            cout << "Название пункта назначения: " << trains[i].destination << endl;
            cout << "Номер поезда: " << trains[i].trainNumber << endl;
            cout << "Время отправления: " << trains[i].departureTime << endl << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Поездов, отправляющихся после " << currentTime << ", не найдено.\n";
    }

    return 0;
}
