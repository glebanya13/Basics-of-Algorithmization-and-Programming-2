#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

// Функция для получения хеш-кода слова
size_t getHashCode(const string& word, size_t tableSize) {
    size_t hash = 0;
    for (char c : word) {
        hash = (hash * 31 + c) % tableSize; // Простая хеш-функция с учетом всех символов слова
    }
    return hash;
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    string filename;
    cout << "Введите имя текстового файла: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла." << endl;
        return 1;
    }

    int tableSize;
    cout << "Введите размер хеш-таблицы: ";
    cin >> tableSize;

    // Хеш-таблица слов
    unordered_map<size_t, list<string>> hashTable;

    string word;
    while (file >> word) {
        size_t hash = getHashCode(word, tableSize); // Получение хеш-кода слова
        hashTable[hash].push_back(word); // Добавление слова в соответствующий список в хеш-таблице
    }

    // Вывод хеш-таблицы
    cout << "Хеш-таблица слов:" << endl;
    for (const auto& kvp : hashTable) {
        cout << "Хеш " << kvp.first << ":";
        for (const string& w : kvp.second) {
            cout << " " << w; // Выводим слова в списке
        }
        cout << endl;
    }

    // Поиск слова
    string searchWord;
    cout << "Введите слово для поиска: ";
    cin >> searchWord;

    size_t searchHash = getHashCode(searchWord, tableSize);
    if (hashTable.count(searchHash) > 0) { // Проверка наличия списка слов по хешу
        bool found = false;
        for (const string& w : hashTable[searchHash]) { // Поиск слова в списке
            if (w == searchWord) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Слово найдено." << endl;
        }
        else {
            cout << "Слово не найдено." << endl;
        }
    }
    else {
        cout << "Слово не найдено." << endl;
    }

    // Удаление слов, начинающихся на указанную букву
    char letterToDelete;
    cout << "Введите букву для удаления слов: ";
    cin >> letterToDelete;

    size_t letterHash = getHashCode(string(1, letterToDelete), tableSize); // Получаем хеш-код для буквы
    if (hashTable.count(letterHash) > 0) {
        hashTable.erase(letterHash); // Удаляем список слов по хешу буквы
    }

    // Вывод хеш-таблицы после удаления
    cout << "Хеш-таблица слов после удаления слов, начинающихся на букву '" << letterToDelete << "':" << endl;
    for (const auto& kvp : hashTable) {
        cout << "Хеш " << kvp.first << ":";
        for (const string& w : kvp.second) {
            cout << " " << w; // Выводим слова в списке
        }
        cout << endl;
    }

    return 0;
}
