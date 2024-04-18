#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

bool containsLetterR(const char* word) {
    int index = 0;
    while (word[index] != '\0') {
        if (word[index] == 'p' || word[index] == 'p') {
            return true;
        }
        index++;
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int maxLength = 1000;
    char inputString[maxLength];
    cout << "Введите строку символов, состоящую из слов, разделенных пробелами: ";
    cin.getline(inputString, maxLength);

    ofstream outFile("FILE1.txt");
    if (!outFile) {
        cerr << "Невозможно открыть файл FILE1.txt для записи!" << endl;
        return 1;
    }
    outFile << inputString;
    outFile.close();

    ifstream inFile("FILE1.txt");
    if (!inFile) {
        cerr << "Невозможно открыть файл FILE1.txt для чтения!" << endl;
        return 1;
    }

    char word[50];
    cout << "Слова, содержащие букву 'р' из файла FILE1.txt:" << endl;
    while (inFile >> word) {
        if (containsLetterR(word)) {
            cout << word << endl;
        }
    }

    inFile.close();

    return 0;
}
