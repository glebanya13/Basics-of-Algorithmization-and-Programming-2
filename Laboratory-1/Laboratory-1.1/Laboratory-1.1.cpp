#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string text;
    cout << "Введите строку: ";
    getline(cin, text); // Ввод строки с пробелами

    ofstream file("data.txt"); // Открытие файла для записи
    if (file.is_open())
    {
        file << text; // Запись строки в файл
        file.close(); // Закрытие файла
    }
    else
    {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    ifstream infile("data.txt"); // Открытие файла для чтения
    if (infile.is_open())
    {
        string word;
        while (infile >> word) // Чтение каждого слова из файла
        {
            if (word.find('х') != string::npos || word.find('Х') != string::npos) // Проверка на наличие буквы "х"
            {
                cout << word << endl; // Вывод слова на экран
            }
        }
        infile.close(); // Закрытие файла
    }
    else
    {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }
    return 0;
}
