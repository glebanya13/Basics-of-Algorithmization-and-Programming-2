#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Структура для хранения подсказки для каждого слова
struct HelpInfo {
    string helpText;
};

// Класс для хранения и управления хеш-таблицей
class HelpTable {
private:
    static const int InitialSize = 20; // Начальный размер таблицы
    unordered_map<string, HelpInfo> table; // Хеш-таблица для хранения слов и их подсказок

public:
    // Метод для добавления слова и его подсказки в таблицу
    void addWord(const string& word, const string& help) {
        table[word].helpText = help;
    }

    // Метод для получения подсказки по слову
    string getHelp(const string& word) {
        if (table.find(word) != table.end()) {
            return table[word].helpText;
        }
        else {
            return "Подсказка для этого слова отсутствует.";
        }
    }

    // Метод для вывода всех слов и соответствующих им подсказок в таблице
    void printTable() {
        cout << "Хеш-таблица слов и их подсказок:" << endl;
        for (const auto& entry : table) {
            cout << "Слово: " << entry.first << ", Подсказка: " << entry.second.helpText << endl;
        }
    }
};

int main() {
    setlocale(LC_CTYPE, "Russian");

    HelpTable helpTable;

    // Добавляем зарезервированные слова и их подсказки
    helpTable.addWord("int", "Тип данных, представляющий целое число.");
    helpTable.addWord("double", "Тип данных, представляющий вещественное число двойной точности.");
    helpTable.addWord("float", "Тип данных для чисел с плавающей запятой одинарной точности.");
    helpTable.addWord("char", "Тип данных для символов.");
    helpTable.addWord("if", "Условный оператор.");
    helpTable.addWord("else", "Оператор ветвления, выполняемый в случае ложного условия в конструкции if.");
    helpTable.addWord("while", "Оператор цикла, выполняющий блок кода, пока условие истинно.");
    helpTable.addWord("for", "Оператор цикла, используемый для повторения блока кода определенное количество раз.");
    helpTable.addWord("break", "Оператор, прерывающий выполнение цикла или оператора switch.");


    // Выводим на экран таблицу
    helpTable.printTable();

    // Получаем подсказку по слову
    string inputWord;
    cout << "Введите слово для получения подсказки: ";
    cin >> inputWord;

    cout << "Подсказка: " << helpTable.getHelp(inputWord) << endl;

    // Добавляем новое слово и его подсказку
    string newWord, newHelp;
    cout << "Введите новое слово: ";
    cin >> newWord;
    cout << "Введите подсказку для этого слова: ";
    cin.ignore(); // Очищаем буфер ввода перед использованием getline
    getline(cin, newHelp);

    helpTable.addWord(newWord, newHelp);

    // Выводим на экран обновленную таблицу
    helpTable.printTable();

    return 0;
}
