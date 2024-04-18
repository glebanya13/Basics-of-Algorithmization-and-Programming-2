#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Функция для генерации случайных чисел в заданном диапазоне
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

void countingSort(int arr[], int size) {
    // Находим максимальное и минимальное значения в массиве
    int max_val = arr[0], min_val = arr[0];
    for (int i = 1; i < size; ++i) {
        max_val = max(max_val, arr[i]);
        min_val = min(min_val, arr[i]);
    }

    // Создаем массив счетчиков и инициализируем его нулями
    int range = max_val - min_val + 1;
    int* count = new int[range]();

    // Считаем количество каждого элемента в исходном массиве
    for (int i = 0; i < size; ++i) {
        count[arr[i] - min_val]++;
    }

    // Строим результирующий массив, используя массив счетчиков
    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (count[i] > 0) {
            arr[index++] = i + min_val;
            count[i]--;
        }
    }

    delete[] count;
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    // Устанавливаем текущее время для генератора случайных чисел
    srand(time(nullptr));

    const int SIZE = 5; // Размер массива

    int arr[SIZE]; // Объявление массива

    // Заполнение массива случайными числами
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = generateRandomNumber(-50, 50); // Генерация случайного числа в диапазоне от -50 до 50
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    countingSort(arr, SIZE);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}