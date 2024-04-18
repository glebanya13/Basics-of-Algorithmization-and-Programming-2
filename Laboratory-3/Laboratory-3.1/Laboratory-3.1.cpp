#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

// Перечисление для марки автомобиля
enum CarBrand
{
    Toyota,
    Honda,
    Ford,
    BMW,
    Mercedes
};

// Перечисление для типа кузова
enum BodyType
{
    Sedan,
    SUV,
    Hatchback,
    Coupe
};

// Структура для даты выпуска с использованием битового поля
struct Date
{
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 11;
};

// Структура для автомобиля
struct Car
{
    CarBrand brand;
    char color[20];
    unsigned int serialNumber;
    Date manufactureDate;
    BodyType bodyType;
    Date lastInspectionDate;
    char owner[50];
};

// Функция для ввода данных об автомобиле с клавиатуры
void inputCar(Car& car)
{
    cout << "Введите марку автомобиля (0 - Toyota, 1 - Honda, 2 - Ford, 3 - BMW, 4 - Mercedes): ";
    int brand;
    cin >> brand;
    car.brand = static_cast<CarBrand>(brand);

    cout << "Введите цвет автомобиля: ";
    cin.ignore(); // очищаем буфер ввода перед использованием getline
    cin.getline(car.color, sizeof(car.color));

    cout << "Введите заводской номер: ";
    cin >> car.serialNumber;

    cout << "Введите дату выпуска (день месяц год): ";
    int day, month, year;
    cin >> day >> month >> year;

    car.manufactureDate.day = static_cast<unsigned int>(day);
    car.manufactureDate.month = static_cast<unsigned int>(month);
    car.manufactureDate.year = static_cast<unsigned int>(year);

    cout << "Введите тип кузова (0 - седан, 1 - внедорожник, 2 - хэтчбек, 3 - купе): ";
    int bodyType;
    cin >> bodyType;
    car.bodyType = static_cast<BodyType>(bodyType);

    cout << "Введите дату последнего техосмотра (день месяц год): ";
    int inspectionDay, inspectionMonth, inspectionYear;
    cin >> inspectionDay >> inspectionMonth >> inspectionYear;

    car.lastInspectionDate.day = static_cast<unsigned int>(inspectionDay);
    car.lastInspectionDate.month = static_cast<unsigned int>(inspectionMonth);
    car.lastInspectionDate.year = static_cast<unsigned int>(inspectionYear);

    cout << "Введите владельца: ";
    cin.ignore(); // очищаем буфер ввода перед использованием getline
    cin.getline(car.owner, sizeof(car.owner));
}

// Функция для вывода данных об автомобиле на экран
void displayCar(const Car& car)
{
    cout << "Марка автомобиля: ";
    switch (car.brand)
    {
    case Toyota:
        cout << "Toyota";
        break;
    case Honda:
        cout << "Honda";
        break;
    case Ford:
        cout << "Ford";
        break;
    case BMW:
        cout << "BMW";
        break;
    case Mercedes:
        cout << "Mercedes";
        break;
    }
    cout << endl;

    cout << "Цвет автомобиля: " << car.color << endl;
    cout << "Заводской номер: " << car.serialNumber << endl;
    cout << "Дата выпуска: " << car.manufactureDate.day << "." << car.manufactureDate.month << "." << car.manufactureDate.year << endl;

    cout << "Тип кузова: ";
    switch (car.bodyType)
    {
    case Sedan:
        cout << "Седан";
        break;
    case SUV:
        cout << "Внедорожник";
        break;
    case Hatchback:
        cout << "Хэтчбек";
        break;
    case Coupe:
        cout << "Купе";
        break;
    }
    cout << endl;

    cout << "Дата последнего техосмотра: " << car.lastInspectionDate.day << "." << car.lastInspectionDate.month << "." << car.lastInspectionDate.year << endl;
    cout << "Владелец: " << car.owner << endl;
}

// Функция для поиска автомобиля по заводскому номеру
Car findCarBySerialNumber(const Car cars[], int size, unsigned int serialNumber)
{

    for (int i = 0; i < size; ++i)
    {
        if (cars[i].serialNumber == serialNumber)
        {
            return cars[i];
        }
    }

    // Если автомобиль не найден, возвращаем пустой автомобиль
    Car emptyCar = { Toyota, "", 0, {0, 0, 0}, Sedan, {0, 0, 0}, "" };
    return emptyCar;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_CARS = 5;
    Car cars[MAX_CARS];
    int carCount = 0;
    int choice;

    do
    {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить автомобиль" << endl;
        cout << "2. Вывести список автомобилей" << endl;
        cout << "3. Поиск по заводскому номеру" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (carCount < MAX_CARS)
            {
                inputCar(cars[carCount]);
                carCount++;
            }
            else
            {
                cerr << "Достигнуто максимальное количество автомобилей." << endl;
            }
            break;
        case 2:
            for (int i = 0; i < carCount; ++i)
            {
                displayCar(cars[i]);
                cout << "------------------------------" << endl;
            }
            break;
        case 3:
            if (carCount > 0)
            {
                unsigned int searchSerialNumber;
                cout << "Введите заводской номер для поиска: ";
                cin >> searchSerialNumber;

                Car foundCar = findCarBySerialNumber(cars, carCount, searchSerialNumber);
                if (foundCar.serialNumber != 0)
                {
                    displayCar(foundCar);
                }
                else
                {
                    cerr << "Автомобиль с указанным заводским номером не найден." << endl;
                }
            }
            else
            {
                cerr << "Список автомобилей пуст." << endl;
            }
            break;
        case 0:
            cout << "Программа завершена." << endl;
            break;
        default:
            cerr << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 0);

    return 0;
}
