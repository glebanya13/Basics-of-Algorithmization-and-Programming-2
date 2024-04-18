#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// Структура для представления информации о преподавателе и экзамене
struct Teacher {
    string lastName;
    string examName;
    string examDate;
};

const int MAX_TEACHERS = 100;  // Максимальное количество преподавателей

// Массив структур для хранения информации о преподавателях
Teacher teachers[MAX_TEACHERS];

int numOfTeachers = 0;  // Текущее количество преподавателей

// Функция для ввода информации о преподавателе с клавиатуры
void inputTeacher() {
    if (numOfTeachers < MAX_TEACHERS) {
        cout << "Введите фамилию преподавателя: ";
        cin >> teachers[numOfTeachers].lastName;
        cout << "Введите название экзамена: ";
        cin >> teachers[numOfTeachers].examName;
        cout << "Введите дату экзамена: ";
        cin >> teachers[numOfTeachers].examDate;
        numOfTeachers++;
    }
    else {
        cout << "Достигнуто максимальное количество преподавателей." << endl;
    }
}

// Функция для вывода информации о всех преподавателях
void outputTeachers() {
    cout << "Список преподавателей:" << endl;
    for (int i = 0; i < numOfTeachers; ++i) {
        cout << "Фамилия: " << teachers[i].lastName << "\tЭкзамен: " << teachers[i].examName
            << "\tДата: " << teachers[i].examDate << endl;
    }
}

// Функция для удаления заданного преподавателя по фамилии
void deleteTeacher() {
    string targetLastName;
    cout << "Введите фамилию преподавателя для удаления: ";
    cin >> targetLastName;

    for (int i = 0; i < numOfTeachers; ++i) {
        if (teachers[i].lastName == targetLastName) {
            // Перемещаем последний элемент на место удаленного
            teachers[i] = teachers[numOfTeachers - 1];
            numOfTeachers--;
            cout << "Преподаватель удален." << endl;
            //return;
        }
    }

    cout << "Преподаватель с указанной фамилией не найден." << endl;
}

// Функция для поиска преподавателя по фамилии
void searchTeacher() {
    string targetLastName;
    cout << "Введите фамилию преподавателя для поиска: ";
    cin >> targetLastName;

    for (int i = 0; i < numOfTeachers; ++i) {
        if (teachers[i].lastName == targetLastName) {
            cout << "Найден преподаватель:" << endl;
            cout << "Фамилия: " << teachers[i].lastName << "\tЭкзамен: " << teachers[i].examName
                << "\tДата: " << teachers[i].examDate << endl;
            return;
        }
    }

    cout << "Преподаватель с указанной фамилией не найден." << endl;
}

// Функция для записи информации в файл
void writeToFile() {
    ofstream outputFile("FILE1.txt");
    if (outputFile.is_open()) {
        for (int i = 0; i < numOfTeachers; ++i) {
            outputFile << teachers[i].lastName << " "
                << teachers[i].examName << " "
                << teachers[i].examDate << endl;
        }
        outputFile.close();
        cout << "Данные успешно записаны в файл." << endl;
    }
    else {
        cout << "Не удалось открыть файл для записи." << endl;
    }
}

// Функция для чтения данных из файла
void readFromFile() {
    ifstream inputFile("FILE1.txt");
    if (inputFile.is_open()) {
        numOfTeachers = 0;  // Обнуляем текущее количество преподавателей перед чтением из файла
        while (inputFile >> teachers[numOfTeachers].lastName
            >> teachers[numOfTeachers].examName
            >> teachers[numOfTeachers].examDate) { // while, который будет выполняться до тех пор, пока данные успешно считываются из файла.
            numOfTeachers++;
            if (numOfTeachers >= MAX_TEACHERS) {
                cout << "Превышено максимальное количество преподавателей при чтении из файла." << endl;
                break;
            }
        }
        inputFile.close();
        cout << "Данные успешно считаны из файла." << endl;
    }
    else {
        cout << "Не удалось открыть файл для чтения." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Ввод информации о преподавателе\n";
        cout << "2. Вывод информации о преподавателях\n";
        cout << "3. Удаление преподавателя\n";
        cout << "4. Поиск преподавателя\n";
        cout << "5. Запись в файл\n";
        cout << "6. Чтение из файла\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            inputTeacher();
            break;
        case 2:
            outputTeachers();
            break;
        case 3:
            deleteTeacher();
            break;
        case 4:
            searchTeacher();
            break;
        case 5:
            writeToFile();
            break;
        case 6:
            readFromFile();
            break;
        case 0:
            cout << "Программа завершена." << endl;
            break;
        default:
            cout << "Неверный выбор. Повторите ввод." << endl;
        }

    } while (choice != 0);

    return 0;
}
