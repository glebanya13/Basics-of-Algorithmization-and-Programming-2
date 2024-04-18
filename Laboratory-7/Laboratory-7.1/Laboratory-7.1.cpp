#include "List.h"
#include <iostream>
#include <windows.h>

void print(void* b)
{
    ExamInfo* info = (ExamInfo*)b;
    std::cout << "Фамилия: " << info->teacherLastName << ", Экзамен: " << info->examName << ", Дата: " << info->examDate << std::endl;
}

void ShowMenu()
{
    std::cout << "1. Вставить элемент" << std::endl;
    std::cout << "2. Найти элемент" << std::endl;
    std::cout << "3. Удалить элемент" << std::endl;
    std::cout << "4. Вывести список" << std::endl;
    std::cout << "5. Удалить весь список" << std::endl;
    std::cout << "6. Подсчитать элементы" << std::endl;
    std::cout << "0. Выйти" << std::endl;
}

int GetUserChoice()
{
    int choice;
    std::cout << "Введите ваш выбор: ";
    std::cin >> choice;
    return choice;
}

ExamInfo GetUserInput()
{
    ExamInfo info;
    std::cout << "Введите фамилию преподавателя: ";
    std::cin >> info.teacherLastName;
    std::cout << "Введите название экзамена: ";
    std::cin >> info.examName;
    std::cout << "Введите дату экзамена: ";
    std::cin >> info.examDate;
    return info;
}

void HandleUserChoice(Object& list, int choice)
{
    switch (choice)
    {
    case 1:
    {
        ExamInfo info = GetUserInput();
        list.Insert(new ExamInfo(info));
        std::cout << "Элемент вставлен." << std::endl;
        break;
    }
    case 2:
    {
        std::string lastName;
        std::cout << "Введите фамилию преподавателя для поиска: ";
        std::cin >> lastName;
        Element* e = list.Search(lastName);
        if (e != nullptr)
        {
            std::cout << "Элемент найден:" << std::endl;
            list.PrintList([](void* data) { std::cout << "Фамилия: " << ((ExamInfo*)data)->teacherLastName << ", Экзамен: " << ((ExamInfo*)data)->examName << ", Дата: " << ((ExamInfo*)data)->examDate << std::endl; }, e);
        }
        else
        {
            std::cout << "Элемент не найден." << std::endl;
        }
        break;
    }
    case 3:
    {
        std::string lastName;
        std::cout << "Введите фамилию преподавателя для удаления: ";
        std::cin >> lastName;
        if (list.Delete(lastName))
        {
            std::cout << "Элемент удален." << std::endl;
        }
        else
        {
            std::cout << "Элемент не найден или не удален." << std::endl;
        }
        break;
    }
    case 4:
        std::cout << "Список экзаменов:" << std::endl;
        list.PrintList([](void* data) { std::cout << "Фамилия: " << ((ExamInfo*)data)->teacherLastName << ", Экзамен: " << ((ExamInfo*)data)->examName << ", Дата: " << ((ExamInfo*)data)->examDate << std::endl; });
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
        std::cout << "Количество элементов в списке: " << list.CountList() << std::endl;
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
