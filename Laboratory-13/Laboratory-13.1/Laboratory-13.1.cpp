// dop2
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

// Функция для сортировки выбором (Selection Sort)
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Обмен значениями между arr[i] и arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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

    // Сортируем массив выбором
    selectionSort(array, SIZE);

    cout << "Массив после сортировки выбором:" << endl;
    printArray(array, SIZE);

    return 0;
}
