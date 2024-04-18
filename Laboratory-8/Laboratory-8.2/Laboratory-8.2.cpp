#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Рекурсивная функция для генерации чисел
void generateNumbers(int A, int currentNumber, int digits, ofstream& outputFile) {
    if (digits == 0) {
        outputFile << to_string(currentNumber) << endl;  // Записываем текущее число в файл
        return;
    }

    for (int digit = 0; digit <= A; ++digit) {
        int newNumber = currentNumber * 10 + digit;  // Обновляем текущее число, добавляя новую цифру
        generateNumbers(A, newNumber, digits - 1, outputFile);  // Рекурсивный вызов с уменьшенным количеством цифр
    }
}

// Функция для генерации чисел и записи их в файл
void generateNumbersFile(int A, int digits, const string& filePath) {
    ofstream outputFile(filePath);  // Открываем файл для записи
    if (!outputFile) {
        cout << "Failed to open the file." << endl;  // Проверяем, успешно ли открыт файл
        return;
    }

    generateNumbers(A, 0, digits, outputFile);  // Генерируем числа и записываем их в файл
    outputFile.close();  // Закрываем файл
}

int main() {
    int A = 5;
    int digits = 2;
    string filePath = "numbers.txt";
    generateNumbersFile(A, digits, filePath);  // Вызываем функцию для генерации чисел и записи их в файл

    return 0;
}
