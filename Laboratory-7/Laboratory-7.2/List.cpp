#include "List.h"
#include <iostream>
#include <map>
#include <numeric>
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

bool Object::Insert(Student* data)
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

Element* Object::Search(std::string last_name)
{
    Element* rc = Head;
    while ((rc != nullptr) && (rc->Data->last_name != last_name))
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

void Object::OrderStudents()
{
    Element* current;
    Student* temp;
    bool swapped;

    do {
        swapped = false;
        current = Head;

        while (current != nullptr && current->Next != nullptr) {
            if (current->Data->course > current->Next->Data->course ||
                (current->Data->course == current->Next->Data->course &&
                    current->Data->last_name > current->Next->Data->last_name)) {
                temp = current->Data;
                current->Data = current->Next->Data;
                current->Next->Data = temp;
                swapped = true;
            }
            current = current->Next;
        }
    } while (swapped);
}

void Object::AverageGradePerGroup()
{
    std::map<std::string, std::map<int, std::pair<int, int>>> groupSubjectStats;

    Element* current = Head;
    while (current != nullptr) {
        std::string group = current->Data->group;
        std::vector<int> grades = current->Data->grades;

        for (int i = 0; i < grades.size(); ++i) {
            int subject = i + 1;
            groupSubjectStats[group][subject].first += grades[i];  // Total grades
            groupSubjectStats[group][subject].second += 1;         // Count of students
        }

        current = current->Next;
    }

    for (const auto& groupEntry : groupSubjectStats) {
        std::cout << "Группа: " << groupEntry.first << std::endl;
        for (const auto& subjectEntry : groupEntry.second) {
            int subject = subjectEntry.first;
            int totalGrades = subjectEntry.second.first;
            int studentCount = subjectEntry.second.second;
            double averageGrade = static_cast<double>(totalGrades) / studentCount;

            std::cout << "Предмет " << subject << ": Средний балл - " << averageGrade << std::endl;
        }
    }
}

void Object::FindOldestYoungest()
{
    Student* oldest = nullptr;
    Student* youngest = nullptr;

    Element* current = Head;
    while (current != nullptr) {
        // Check if the current student is older than the current oldest or younger than the current youngest
        if (!oldest || current->Data->birth_year < oldest->birth_year) {
            oldest = current->Data;
        }
        if (!youngest || current->Data->birth_year > youngest->birth_year) {
            youngest = current->Data;
        }

        current = current->Next;
    }

    if (oldest && youngest) {
        std::cout << "Самый старший студент: " << oldest->first_name << " " << oldest->last_name << std::endl;
        std::cout << "Самый младший студент: " << youngest->first_name << " " << youngest->last_name << std::endl;
    }
    else {
        std::cout << "Не удалось найти старшего и младшего студентов." << std::endl;
    }
}


void Object::BestStudentPerGroup()
{
    std::map<std::string, Student*> bestStudents;

    Element* current = Head;
    while (current != nullptr) {
        std::string group = current->Data->group;
        std::vector<int> grades = current->Data->grades;

        double averageGrade = std::accumulate(grades.begin(), grades.end(), 0.0) / grades.size();

        if (!bestStudents[group] || averageGrade > bestStudents[group]->averageGrade) {
            bestStudents[group] = current->Data;
            bestStudents[group]->averageGrade = averageGrade;
        }

        current = current->Next;
    }

    for (const auto& entry : bestStudents) {
        std::cout << "Группа: " << entry.first << ", Лучший студент: " << entry.second->first_name << " " << entry.second->last_name << std::endl;
    }
}
