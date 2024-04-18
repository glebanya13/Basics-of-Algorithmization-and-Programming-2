#include "List.h"
#include <iostream>

Element* Object::GetLast()
{
    Element* e = Head, * rc = e;
    while (e != nullptr)
    {
        rc = e;
        e = e->Next;
    }
    return rc;
}

bool Object::Insert(ExamInfo* data)
{
    if (data == nullptr) {
        std::cout << "Ошибка: передан нулевой указатель для вставки." << std::endl;
        return false;
    }

    if (Head == nullptr)
    {
        Head = new Element(nullptr, data, nullptr);
        return true;
    }
    else
    {
        Head = new Element(nullptr, data, Head);
        if (Head->Next != nullptr)
        {
            Head->Next->Prev = Head;
        }
        return true;
    }
}

Element* Object::Search(std::string teacherLastName)
{
    Element* rc = Head;
    while ((rc != nullptr) && (rc->Data->teacherLastName != teacherLastName))
        rc = rc->Next;
    return rc;
}

bool Object::Delete(Element* e)
{
    bool rc = false;
    if (e != nullptr)
    {
        if (e->Next != nullptr)
            e->Next->Prev = e->Prev;
        if (e->Prev != nullptr)
            e->Prev->Next = e->Next;
        else
            Head = e->Next;
        delete e;
        rc = true;
    }
    return rc;
}

bool Object::Delete(std::string teacherLastName)
{
    Element* e = Search(teacherLastName);
    if (e == nullptr) {
        std::cout << "Ошибка: элемент с фамилией " << teacherLastName << " не найден." << std::endl;
        return false;
    }

    return Delete(e);
}

bool Object::DeleteList()
{
    Element* current = Head;
    while (current != nullptr)
    {
        Element* next = current->Next;
        delete current;  // Удаление самого элемента, не освобождаем память для данных, так как она уже освобождена в деструкторе элемента
        current = next;
    }
    Head = nullptr;
    return true;
}

int Object::CountList()
{
    int count = 0;
    Element* current = Head;
    while (current != nullptr)
    {
        count++;
        current = current->Next;
    }
    return count;
}

void Object::PrintList(void(*f)(void*))
{
    Element* e = Head;
    while (e != nullptr)
    {
        f(e->Data);
        e = e->Next;
    }
}

void Object::PrintList(void(*f)(void*), Element* e)
{
    f(e->Data);
}

Object Create()
{
    return Object();
}
