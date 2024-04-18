#include <iostream>
#include <fstream>

using namespace std;

bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

int main() {
    setlocale(LC_ALL, "ru");
    char str[100];

    // Ввод строки символов с клавиатуры
    cout << "Введите строку символов, состоящую из групп цифр и нулей: ";
    cin.getline(str, 100);

    // Запись строки в файл
    ofstream file("data.txt");
    if (file.is_open()) {
        file << str;
        file.close();
        cout << "Строка успешно записана в файл.\n";
    }
    else {
        cout << "Ошибка открытия файла для записи.\n";
        return 1;
    }

    // Чтение данных из файла и вывод групп с четным количеством символов
    ifstream inputFile("data.txt");
    if (inputFile.is_open()) {
        char ch;
        string group;
        bool groupStarted = false;

        while (inputFile.get(ch)) {
            if (isDigit(ch) || ch == '0') {
                group += ch;
                groupStarted = true;
            }
            else if (groupStarted) {
                if (group.length() % 2 == 0) {
                    cout << "Группа с четным количеством символов: " << group << endl;
                }
                group.clear();
                groupStarted = false;
            }
        }

        if (groupStarted && group.length() % 2 == 0) {
            cout << "Группа с четным количеством символов: " << group << endl;
        }

        inputFile.close();
    }
    else {
        cout << "Ошибка открытия файла для чтения.\n";
        return 1;
    }

    return 0;
}
