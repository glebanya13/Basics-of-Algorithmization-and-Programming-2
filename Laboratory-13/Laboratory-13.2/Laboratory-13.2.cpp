// dop3
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Функция для генерации случайных чисел в заданном диапазоне
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Функция для вывода массива на экран
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функция для сортировки методом простой вставки (Insertion Sort)
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        // Перемещаем элементы arr[0..i-1], которые больше key, на одну позицию вперед
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    // Устанавливаем текущее время для генератора случайных чисел
    srand(time(nullptr));

    const int SIZE = 10;
    int array[SIZE];

    cout << "Исходный массив:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        array[i] = generateRandomNumber(1, 100);
    }
    printArray(array, SIZE);

    // Сортируем массив методом простой вставки
    insertionSort(array, SIZE);

    cout << "Массив после сортировки методом простой вставки:" << endl;
    printArray(array, SIZE);

    return 0;
}