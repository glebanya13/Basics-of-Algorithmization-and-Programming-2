#include "List.h"
#include <iostream>
#include <windows.h>

void print(void* b)
{
    Student* student = (Student*)b;
    std::cout << "Фамилия: " << student->last_name << ", Имя: " << student->first_name << ", Отчество: " << student->patronymic << ", Год рождения: " << student->birth_year << ", Курс: " << student->course << ", Группа: " << student->group << std::endl;
}

void ShowMenu()
{
    std::cout << "1. Вставить элемент" << std::endl;
    std::cout << "2. Найти элемент" << std::endl;
    std::cout << "3. Удалить элемент" << std::endl;
    std::cout << "4. Вывести список" << std::endl;
    std::cout << "5. Удалить весь список" << std::endl;
    std::cout << "6. Подсчитать элементы" << std::endl;
    std::cout << "7. Упорядочить студентов по курсу и алфавиту" << std::endl;
    std::cout << "8. Средний балл каждой группы по каждому предмету" << std::endl;
    std::cout << "9. Найти самого старшего и самого младшего студента" << std::endl;
    std::cout << "10. Найти лучшего студента в каждой группе" << std::endl;
    std::cout << "0. Выйти" << std::endl;
}

int GetUserChoice()
{
    int choice;
    std::cout << "Введите ваш выбор: ";
    std::cin >> choice;
    return choice;
}

Student GetUserInput()
{
    Student student;
    std::cout << "Введите фамилию студента: ";
    std::cin >> student.last_name;
    std::cout << "Введите имя студента: ";
    std::cin >> student.first_name;
    std::cout << "Введите отчество студента: ";
    std::cin >> student.patronymic;
    std::cout << "Введите год рождения студента: ";
    std::cin >> student.birth_year;
    std::cout << "Введите курс студента: ";
    std::cin >> student.course;
    std::cout << "Введите номер группы студента: ";
    std::cin >> student.group;

    std::cout << "Введите оценки по пяти предметам для студента:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        int grade;
        std::cout << "Введите оценку " << i + 1 << ": ";
        std::cin >> grade;
        student.grades.push_back(grade);
    }

    return student;
}

void HandleUserChoice(Object& list, int choice)
{
    switch (choice)
    {
    case 1:
    {
        Student student = GetUserInput();
        list.Insert(new Student(student));
        std::cout << "Студент добавлен." << std::endl;
        break;
    }
    case 2:
    {
        std::string lastName;
        std::cout << "Введите фамилию студента для поиска: ";
        std::cin >> lastName;
        Element* e = list.Search(lastName);
        if (e != nullptr)
        {
            std::cout << "Студент найден:" << std::endl;
            list.PrintList(print, e);
        }
        else
        {
            std::cout << "Студент не найден." << std::endl;
        }
        break;
    }
    case 3:
    {
        std::string lastName;
        std::cout << "Введите фамилию студента для удаления: ";
        std::cin >> lastName;
        if (list.Delete(lastName))
        {
            std::cout << "Студент удален." << std::endl;
        }
        else
        {
            std::cout << "Студент не найден или не удален." << std::endl;
        }
        break;
    }
    case 4:
        std::cout << "Список студентов:" << std::endl;
        list.PrintList(print);
        break;
    case 5:
        if (list.DeleteList())
        {
            std::cout << "Список удален." << std::endl;
        }
        else
        {
            std::cout << "Ошибка при удалении списка." << std::endl;
        }
        break;
    case 6:
        std::cout << "Количество студентов в списке: " << list.CountList() << std::endl;
        break;
    case 7:
        list.OrderStudents();
        std::cout << "Студенты упорядочены по курсу и алфавиту." << std::endl;
        break;
    case 8:
        list.AverageGradePerGroup();
        break;
    case 9:
        list.FindOldestYoungest();
        break;
    case 10:
        list.BestStudentPerGroup();
        break;
    case 0:
        std::cout << "Завершение программы." << std::endl;
        break;
    default:
        std::cout << "Некорректный выбор." << std::endl;
        break;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    bool rc;
    Object L1 = Create();   // создание списка с именем L1

    int choice;
    do
    {
        ShowMenu();
        choice = GetUserChoice();
        HandleUserChoice(L1, choice);
    } while (choice != 0);

    return 0;
}
