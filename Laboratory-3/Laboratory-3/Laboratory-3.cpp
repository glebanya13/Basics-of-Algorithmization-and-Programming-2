#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

// Перечисление для специальностей
enum Specialization
{
    ComputerScience,
    Math,
    Engineering,
    Business,
};

// Структура для конкурса прошлого года
struct LastYearCompetition
{
    unsigned int computerScience : 8;
    unsigned int math : 8;
    unsigned int engineering : 8;
    unsigned int business : 8;
};

// Структура для абитуриента
struct Applicant
{
    char universityName[50];
    char address[100];
    Specialization specialty;
    LastYearCompetition lastYearCompetition;
    double tuitionFee;
};

// Функция для ввода данных абитуриента с клавиатуры
void inputApplicant(Applicant& applicant)
{
    cout << "Введите название вуза: ";
    cin.ignore(); // очищаем буфер ввода перед использованием getline
    cin.getline(applicant.universityName, sizeof(applicant.universityName));

    cout << "Введите адрес вуза: ";
    cin.getline(applicant.address, sizeof(applicant.address));

    cout << "Выберите специальность (0 - Информатика, 1 - Математика, 2 - Инженерное дело, 3 - Бизнес): ";
    int specialization;
    cin >> specialization;
    applicant.specialty = static_cast<Specialization>(specialization);

    cout << "Введите конкурс прошлого года для каждой специальности (от 0 до 255): ";
    int computerScience, math, engineering, business;
    cin >> computerScience >> math >> engineering >> business;

    applicant.lastYearCompetition.computerScience = static_cast<unsigned int>(computerScience);
    applicant.lastYearCompetition.math = static_cast<unsigned int>(math);
    applicant.lastYearCompetition.engineering = static_cast<unsigned int>(engineering);
    applicant.lastYearCompetition.business = static_cast<unsigned int>(business);

    cout << "Введите размер оплаты при договорном обучении: ";
    cin >> applicant.tuitionFee;
}

// Функция для вывода данных абитуриента на экран
void displayApplicant(const Applicant& applicant)
{
    cout << "Название вуза: " << applicant.universityName << endl;
    cout << "Адрес вуза: " << applicant.address << endl;
    cout << "Специальность: ";
    switch (applicant.specialty)
    {
    case ComputerScience:
        cout << "Информатика";
        break;
    case Math:
        cout << "Математика";
        break;
    case Engineering:
        cout << "Инженерное дело";
        break;
    case Business:
        cout << "Бизнес";
        break;
    }
    cout << endl;
    cout << "Конкурс прошлого года: "
        << "Информатика: " << applicant.lastYearCompetition.computerScience << ", "
        << "Математика: " << applicant.lastYearCompetition.math << ", "
        << "Инженерка: " << applicant.lastYearCompetition.engineering << ", "
        << "Бизнес: " << applicant.lastYearCompetition.business << endl;
    cout << "Размер оплаты при договорном обучении: " << applicant.tuitionFee << endl;
}

// Функция для удаления данных абитуриента
void deleteApplicant(Applicant& applicant)
{
    // Просто обнуляем поля
    memset(applicant.universityName, 0, sizeof(applicant.universityName));
    memset(applicant.address, 0, sizeof(applicant.address));
    applicant.specialty = ComputerScience;
    applicant.lastYearCompetition.computerScience = 0;
    applicant.lastYearCompetition.math = 0;
    applicant.lastYearCompetition.engineering = 0;
    applicant.lastYearCompetition.business = 0;
    applicant.tuitionFee = 0.0;
}

// Функция для поиска абитуриента с минимальным конкурсом
Applicant findMinCompetitionApplicant(const Applicant applicants[], int size)
{
    if (size == 0)
    {
        cerr << "Список абитуриентов пуст." << endl;
        // Возвращаем пустого абитуриента
        Applicant emptyApplicant;
        deleteApplicant(emptyApplicant);
        return emptyApplicant;
    }

    // Находим первого абитуриента
    Applicant minCompetitionApplicant = applicants[0];

    // Проходим по остальным абитуриентам и сравниваем конкурс прошлого года
    for (int i = 1; i < size; ++i)
    {
        if (applicants[i].lastYearCompetition.computerScience < minCompetitionApplicant.lastYearCompetition.computerScience)
        {
            minCompetitionApplicant = applicants[i];
        }
    }

    return minCompetitionApplicant;
}

int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    const int MAX_APPLICANTS = 5;
    Applicant applicants[MAX_APPLICANTS];
    int applicantCount = 0;
    int choice;

    do
    {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить абитуриента" << endl;
        cout << "2. Вывести список абитуриентов" << endl;
        cout << "3. Удалить абитуриента" << endl;
        cout << "4. Поиск по минимальному конкурсу" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (applicantCount < MAX_APPLICANTS)
            {
                inputApplicant(applicants[applicantCount]);
                applicantCount++;
            }
            else
            {
                cerr << "Достигнуто максимальное количество абитуриентов." << endl;
            }
            break;
        case 2:
            for (int i = 0; i < applicantCount; ++i)
            {
                displayApplicant(applicants[i]);
                cout << "------------------------------" << endl;
            }
            break;
        case 3:
            if (applicantCount > 0)
            {
                int indexToDelete;
                cout << "Введите номер абитуриента для удаления (от 1 до " << applicantCount << "): ";
                cin >> indexToDelete;

                if (indexToDelete >= 1 && indexToDelete <= applicantCount)
                {
                    deleteApplicant(applicants[indexToDelete - 1]);
                    cout << "Абитуриент удален." << endl;
                }
                else
                {
                    cerr << "Некорректный номер абитуриента." << endl;
                }
            }
            else
            {
                cerr << "Список абитуриентов пуст." << endl;
            }
            break;
        case 4:
            displayApplicant(findMinCompetitionApplicant(applicants, applicantCount));
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
