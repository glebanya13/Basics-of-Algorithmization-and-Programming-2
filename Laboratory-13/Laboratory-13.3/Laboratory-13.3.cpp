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

// Функция для сортировки методом Шелла (Shell sort)
void shellSort(int arr[], int size) {
    // Начинаем с большего шага, а затем уменьшаем его
    for (int gap = size / 2; gap > 0; gap /= 2) {
        // Применяем метод простой вставки с текущим шагом gap
        for (int i = gap; i < size; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
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
        array[i] = generateRandomNumber(1, 6);
    }
    printArray(array, SIZE);

    // Сортируем массив методом Шелла
    shellSort(array, SIZE);

    cout << "Массив после сортировки методом Шелла:" << endl;
    printArray(array, SIZE);

    return 0;
}
