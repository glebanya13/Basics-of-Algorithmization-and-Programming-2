#pragma once
#include <string>
#include <vector>

struct Student {
    std::string last_name;
    std::string first_name;
    std::string patronymic;
    int birth_year;
    int course;
    std::string group;
    std::vector<int> grades;
    double averageGrade;
};

struct Element
{
    Element* Prev;
    Element* Next;
    Student* Data;

    Element(Element* prev, Student* data, Element* next)
    {
        Prev = prev;
        Data = data;
        Next = next;
    }

    Element* GetNext()
    {
        return Next;
    }

    Element* GetPrev()
    {
        return Prev;
    }

    ~Element()
    {
        delete Data;
    }
};

struct Object
{
    Element* Head;

    Object()
    {
        Head = nullptr;
    }

    Element* GetFirst()
    {
        return Head;
    }

    Element* GetLast();
    Element* Search(std::string teacherLastName);
    bool Insert(Student* data);
    bool InsertEnd(Student* data);
    bool Delete(Element* e);
    bool Delete(std::string teacherLastName);
    bool DeleteList();
    void PrintList(void(*f)(void*));
    void PrintList(void(*f)(void*), Element* e);  // Вторая перегрузка
    int CountList();
    bool DeleteDouble();
    void OrderStudents();
    void AverageGradePerGroup();
    void FindOldestYoungest();
    void BestStudentPerGroup();

    ~Object()
    {
        DeleteList();
    }
};

Object Create();
