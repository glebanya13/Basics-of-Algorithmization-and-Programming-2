#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <Windows.h>

using namespace std;

// Функция для проверки, является ли символ согласной буквой
bool isConsonant(char c) {
    // Английский алфавит
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        // Проверяем, является ли символ буквой и не гласной
        return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U');
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string sourceFilename = "FILE1.txt";
    string destFilename = "FILE2.txt";
    int startLine, endLine;

    cout << "Введите номер начальной строки для копирования: ";
    cin >> startLine;

    cout << "Введите номер конечной строки для копирования: ";
    cin >> endLine;

    ifstream sourceFile(sourceFilename); //создаются объекты для чтения
    ofstream destFile(destFilename); //создаются объекты для записи
    int consonantCount = 0;

    if (sourceFile && destFile) { // Проверяем, успешно ли открыли файлы
        string line;
        int lineCount = 1;

        while (getline(sourceFile, line)) { // Считываем строки из исходного файла
            if (lineCount >= startLine && lineCount <= endLine) {
                destFile << line << endl;
            }

            lineCount++;
        }

        cout << "Строки успешно скопированы в файл " << destFilename << endl;

        sourceFile.close();
        destFile.close();


        // Открыть FILE2.txt для подсчета согласных букв
        ifstream destFileCount(destFilename);
        if (destFileCount) {
            char ch;
            int consonantCountInFile2 = 0;
            while (destFileCount.get(ch)) {
                if (isConsonant(ch)) {
                    consonantCountInFile2++;
                }
            }
            cout << "Количество согласных букв в файле " << destFilename << ": " << consonantCountInFile2 << endl;
            destFileCount.close();
        }

        else {
            cout << "Ошибка открытия файла для подсчета согласных букв.\n";
        }
    }
    else {
        cout << "Ошибка открытия файлов.\n";
    }

    return 0;
}
