#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

// функция для подсчета количества цифр в слове
int count_digits(const string& word) {
    int count = 0;
    for (char c : word) {
        if (isdigit(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    setlocale(LC_ALL, "rus");
    ifstream input_file("FILE1.txt");
    if (!input_file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл для чтения\n";
        return 1;
    }

    ofstream output_file("FILE2.txt");
    if (!output_file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл для записи\n";
        return 1;
    }

    string line;
    int line_number = 0;
    while (getline(input_file, line)) {
        stringstream ss(line);
        unordered_map<string, int> word_counts;
        string word;
        while (ss >> word) {
            word_counts[word]++;
        }
        bool found_repeated = false;
        for (const auto& pair : word_counts) {
            if (pair.second >= 2) {
                found_repeated = true;
                break;
            }
        }
        if (found_repeated) {
            output_file << line << '\n';
        }
        line_number++;
    }

    input_file.close();
    output_file.close();

    // открываем файл FILE2.txt для чтения
    ifstream input_file2("FILE2.txt");
    if (!input_file2.is_open()) {
        cerr << "Ошибка: не удалось открыть файл для чтения\n";
        return 1;
    }

    int max_digits = 0;  // максимальное количество цифр в слове
    int word_number = 0;  // номер слова, в котором больше всего цифр
    line_number = 0;
    while (getline(input_file2, line)) { // чтение строки из потока input_file2 и сохранение ее в переменной line
        stringstream ss(line); // stringstream позволяет использовать потоковые операции для работы со строками
        string word;
        int current_word_number = 0;
        while (ss >> word) {
            current_word_number++;
            int num_digits = count_digits(word);
            if (num_digits > max_digits) {
                max_digits = num_digits;
                word_number = current_word_number;
            }
        }
        line_number++;
    }

    input_file2.close();

    cout << "Слово под номером " << word_number << " содержит максимальное количество цифр (" << max_digits << ")\n";

    return 0;
}