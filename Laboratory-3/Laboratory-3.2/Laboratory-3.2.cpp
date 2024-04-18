#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

// Перечисление для должности сотрудника
enum Position
{
    Manager,
    Engineer,
    Accountant,
    Technician
};

// Структура для даты
struct Date
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

// Структура для сотрудника
struct Employee
{
    char fullName[50];
    char education[50];
    char specialty[50];
    char department[50];
    Position position;
    double salary;
    Date employmentDate;
};

// Функция для ввода данных о сотруднике с клавиатуры
void inputEmployee(Employee& emp)
{
    cout << "Введите Ф.И.О. работника: ";
    cin.ignore();
    cin.getline(emp.fullName, sizeof(emp.fullName));

    cout << "Введите образование работника: ";
    cin.getline(emp.education, sizeof(emp.education));

    cout << "Введите специальность работника: ";
    cin.getline(emp.specialty, sizeof(emp.specialty));

    cout << "Введите подразделение работника: ";
    cin.getline(emp.department, sizeof(emp.department));

    cout << "Введите должность работника (0 - Менеджер, 1 - Инженер, 2 - Бухгалтер, 3 - Техник): ";
    int position;
    cin >> position;
    emp.position = static_cast<Position>(position);

    cout << "Введите оклад работника: ";
    cin >> emp.salary;

    cout << "Введите дату поступления на предприятие (день месяц год): ";
    cin >> emp.employmentDate.day >> emp.employmentDate.month >> emp.employmentDate.year;
}

// Функция для вывода данных о сотруднике на экран
void displayEmployee(const Employee& emp)
{
    cout << "Ф.И.О. работника: " << emp.fullName << endl;
    cout << "Образование: " << emp.education << endl;
    cout << "Специальность: " << emp.specialty << endl;
    cout << "Подразделение: " << emp.department << endl;

    cout << "Должность: ";
    switch (emp.position)
    {
    case Manager:
        cout << "Менеджер";
        break;
    case Engineer:
        cout << "Инженер";
        break;
    case Accountant:
        cout << "Бухгалтер";
        break;
    case Technician:
        cout << "Техник";
        break;
    }
    cout << endl;

    cout << "Оклад: " << emp.salary << endl;
    cout << "Дата поступления на предприятие: " << emp.employmentDate.day << "." << emp.employmentDate.month << "." << emp.employmentDate.year << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_EMPLOYEES = 5;
    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int choice;

    do
    {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить сотрудника" << endl;
        cout << "2. Вывести список сотрудников" << endl;
        cout << "3. Поиск по должности" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (employeeCount < MAX_EMPLOYEES)
            {
                inputEmployee(employees[employeeCount]);
                employeeCount++;
            }
            else
            {
                cerr << "Достигнуто максимальное количество сотрудников." << endl;
            }
            break;
        case 2:
            for (int i = 0; i < employeeCount; ++i)
            {
                displayEmployee(employees[i]);
                cout << "------------------------------" << endl;
            }
            break;
        case 3:
            if (employeeCount > 0)
            {
                int searchPosition;
                cout << "Введите должность для поиска (0 - Менеджер, 1 - Инженер, 2 - Бухгалтер, 3 - Техник): ";
                cin >> searchPosition;


                cout << "\nСотрудники с должностью: ";
                switch (static_cast<Position>(searchPosition))
                {
                case Manager:
                    cout << "Менеджер" << endl;
                    break;
                case Engineer:
                    cout << "Инженер" << endl;
                    break;
                case Accountant:
                    cout << "Бухгалтер" << endl;
                    break;
                case Technician:
                    cout << "Техник" << endl;
                    break;
                }

                bool found = false;
                for (int i = 0; i < employeeCount; ++i)
                {
                    if (employees[i].position == static_cast<Position>(searchPosition))
                    {
                        displayEmployee(employees[i]);
                        cout << "------------------------------" << endl;
                        found = true;
                    }
                }

                if (!found)
                {
                    cerr << "Сотрудников с указанной должностью не найдено." << endl;
                }
            }
            else
            {
                cerr << "Список сотрудников пуст." << endl;
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
