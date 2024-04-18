// dop1
#include <iostream>
#include <string>

using namespace std;

// Структура для хранения элемента в хеш-таблице
struct HashElement {
    char key;
    int count;
};

// Класс для хранения и работы с хеш-таблицей
class HashTable {
private:
    static const int TableSize = 26; // размер таблицы для хранения буквенных символов
    HashElement table[TableSize]; // массив элементов таблицы

public:
    // Конструктор, инициализирующий таблицу
    HashTable() {
        for (int i = 0; i < TableSize; ++i) {
            table[i].key = 'a' + i; // заполняем ключи таблицы от 'a' до 'z'
            table[i].count = 0; // инициализируем счетчики вхождений нулем
        }
    }

    // Метод для добавления символа в таблицу
    void insert(char ch) {
        if (isalpha(ch)) { // проверяем, является ли символ буквой
            ch = tolower(ch); // приводим символ к нижнему регистру
            int index = ch - 'a'; // вычисляем индекс в таблице
            table[index].count++; // увеличиваем счетчик вхождений
        }
    }

    // Метод для вывода содержимого таблицы
    void print() {
        cout << "Хеш-таблица букв и их количества в строке:" << endl;
        for (int i = 0; i < TableSize; ++i) {
            if (table[i].count > 0) {
                cout << "'" << table[i].key << "': " << table[i].count << endl;
            }
        }
    }

    // Метод для проверки наличия символа в таблице
    bool search(char ch) {
        if (isalpha(ch)) { // проверяем, является ли символ буквой
            ch = tolower(ch); // приводим символ к нижнему регистру
            int index = ch - 'a'; // вычисляем индекс в таблице
            return table[index].count > 0; // возвращаем true, если счетчик вхождений больше 0
        }
        return false; // возвращаем false, если символ не является буквой
    }
};

int main() {
    setlocale(LC_CTYPE, "Russian");
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    HashTable ht;
    for (char ch : input) {
        ht.insert(ch); // добавляем каждый символ строки в хеш-таблицу
    }

    ht.print();

    char letter;
    cout << "Введите букву для поиска: ";
    cin >> letter;

    if (ht.search(letter)) {
        cout << "Буква '" << letter << "' найдена в строке." << endl;
    }
    else {
        cout << "Буква '" << letter << "' не найдена в строке." << endl;
    }

    return 0;
}
