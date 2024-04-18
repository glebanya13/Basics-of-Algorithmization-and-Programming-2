#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // Ввод строки с клавиатуры
    string input;
    cout << "Введите строку цифр и нулей, разделяя группы пробелами: ";
    getline(cin, input);

    // Запись строки в файл
    ofstream file("data.txt");
    if (file.is_open()) {
        file << input;
        file.close();
    }
    else {
        cout << "Ошибка при открытии файла!" << endl;
        return 1;
    }

    // Чтение данных из файла
    ifstream infile("data.txt");
    if (infile.is_open()) {
        string content((istreambuf_iterator<char>(infile)), (istreambuf_iterator<char>()));
        // Чтение содержимого файла и сохранение его в строку 'content'
        // Используется итератор потока для чтения каждого символа из файла
        // Полученные символы добавляются к строке 'content'
        // infile - объект ifstream, представляющий открытый файл для чтения

        // Поиск самой короткой группы
        string shortest_group;
        string current_group;
        for (int i = 0; i < content.length(); i++) {
            if (content[i] == ' ') {
                if (shortest_group.empty() || current_group.length() < shortest_group.length()) {
                    shortest_group = current_group;
                }
                current_group.clear();
            }
            else {
                current_group += content[i];
            }
        }
        if (!current_group.empty() && (shortest_group.empty() || current_group.length() < shortest_group.length())) {
            shortest_group = current_group;
        }

        // Вывод самой короткой группы
        cout << "Самая короткая группа: " << shortest_group << endl;
        infile.close();
    }
    else {
        cout << "Ошибка при открытии файла!" << endl;
        return 1;
    }

    return 0;
}
