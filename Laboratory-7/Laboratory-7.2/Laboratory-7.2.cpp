#include "List.h"
#include <iostream>
#include <windows.h>

void print(void* b)
{
    Student* student = (Student*)b;
    std::cout << "�������: " << student->last_name << ", ���: " << student->first_name << ", ��������: " << student->patronymic << ", ��� ��������: " << student->birth_year << ", ����: " << student->course << ", ������: " << student->group << std::endl;
}

void ShowMenu()
{
    std::cout << "1. �������� �������" << std::endl;
    std::cout << "2. ����� �������" << std::endl;
    std::cout << "3. ������� �������" << std::endl;
    std::cout << "4. ������� ������" << std::endl;
    std::cout << "5. ������� ���� ������" << std::endl;
    std::cout << "6. ���������� ��������" << std::endl;
    std::cout << "7. ����������� ��������� �� ����� � ��������" << std::endl;
    std::cout << "8. ������� ���� ������ ������ �� ������� ��������" << std::endl;
    std::cout << "9. ����� ������ �������� � ������ �������� ��������" << std::endl;
    std::cout << "10. ����� ������� �������� � ������ ������" << std::endl;
    std::cout << "0. �����" << std::endl;
}

int GetUserChoice()
{
    int choice;
    std::cout << "������� ��� �����: ";
    std::cin >> choice;
    return choice;
}

Student GetUserInput()
{
    Student student;
    std::cout << "������� ������� ��������: ";
    std::cin >> student.last_name;
    std::cout << "������� ��� ��������: ";
    std::cin >> student.first_name;
    std::cout << "������� �������� ��������: ";
    std::cin >> student.patronymic;
    std::cout << "������� ��� �������� ��������: ";
    std::cin >> student.birth_year;
    std::cout << "������� ���� ��������: ";
    std::cin >> student.course;
    std::cout << "������� ����� ������ ��������: ";
    std::cin >> student.group;

    std::cout << "������� ������ �� ���� ��������� ��� ��������:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        int grade;
        std::cout << "������� ������ " << i + 1 << ": ";
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
        std::cout << "������� ��������." << std::endl;
        break;
    }
    case 2:
    {
        std::string lastName;
        std::cout << "������� ������� �������� ��� ������: ";
        std::cin >> lastName;
        Element* e = list.Search(lastName);
        if (e != nullptr)
        {
            std::cout << "������� ������:" << std::endl;
            list.PrintList(print, e);
        }
        else
        {
            std::cout << "������� �� ������." << std::endl;
        }
        break;
    }
    case 3:
    {
        std::string lastName;
        std::cout << "������� ������� �������� ��� ��������: ";
        std::cin >> lastName;
        if (list.Delete(lastName))
        {
            std::cout << "������� ������." << std::endl;
        }
        else
        {
            std::cout << "������� �� ������ ��� �� ������." << std::endl;
        }
        break;
    }
    case 4:
        std::cout << "������ ���������:" << std::endl;
        list.PrintList(print);
        break;
    case 5:
        if (list.DeleteList())
        {
            std::cout << "������ ������." << std::endl;
        }
        else
        {
            std::cout << "������ ��� �������� ������." << std::endl;
        }
        break;
    case 6:
        std::cout << "���������� ��������� � ������: " << list.CountList() << std::endl;
        break;
    case 7:
        list.OrderStudents();
        std::cout << "�������� ����������� �� ����� � ��������." << std::endl;
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
        std::cout << "���������� ���������." << std::endl;
        break;
    default:
        std::cout << "������������ �����." << std::endl;
        break;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    bool rc;
    Object L1 = Create();   // �������� ������ � ������ L1

    int choice;
    do
    {
        ShowMenu();
        choice = GetUserChoice();
        HandleUserChoice(L1, choice);
    } while (choice != 0);

    return 0;
}
