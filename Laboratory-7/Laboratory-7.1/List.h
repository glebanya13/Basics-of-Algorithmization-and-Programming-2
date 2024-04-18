#pragma once

#include <string>

struct ExamInfo
{
    std::string teacherLastName;
    std::string examName;
    std::string examDate;
};

struct Element
{
    Element* Prev;
    Element* Next;
    ExamInfo* Data;

    Element(Element* prev, ExamInfo* data, Element* next)
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
    bool Insert(ExamInfo* data);
    bool InsertEnd(ExamInfo* data);
    bool Delete(Element* e);
    bool Delete(std::string teacherLastName);
    bool DeleteList();
    void PrintList(void(*f)(void*));
    void PrintList(void(*f)(void*), Element* e);  // Вторая перегрузка
    int CountList();
    bool DeleteDouble();

    ~Object()
    {
        DeleteList();
    }
};

Object Create();
