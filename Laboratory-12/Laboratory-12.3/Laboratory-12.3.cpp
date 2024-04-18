#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

// Функция для получения хеш-кода целого числа
size_t getHashCode(int num, size_t tableSize) {
    // Простая хеш-функция, вычисляющая остаток от деления числа на размер таблицы
    return num % tableSize;
}

// Функция для поиска числа в хеш-таблице
bool searchNumber(const unordered_set<int>& hashTable, int num) {
    // Проверяем, содержится ли число в хеш-таблице
    return hashTable.find(num) != hashTable.end();
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

    // Задаем размер хеш-таблицы
    size_t tableSize;
    cout << "Введите размер хеш-таблицы: ";
    cin >> tableSize;

    // Строим хеш-таблицу из чисел файла
    unordered_set<int> hashTable;
    int num;
    while (file >> num) {
        size_t hash = getHashCode(num, tableSize); // Вычисляем хеш для числа
        hashTable.insert(num); // Вставляем число в хеш-таблицу
    }

    // Ввод числа для поиска
    int searchNum;
    cout << "Введите целое число для поиска: ";
    cin >> searchNum;

    // Поиск числа в хеш-таблице
    if (searchNumber(hashTable, searchNum)) {
        cout << "Число " << searchNum << " найдено в хеш-таблице." << endl;
    }
    else {
        cout << "Число " << searchNum << " не найдено в хеш-таблице." << endl;
    }

    return 0;
}
