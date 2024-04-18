#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

// Функция генерации случайного целого числа в заданном диапазоне
int randInt(int min, int max) {
    static random_device rd; // равномерно распределенные случайные числа.
    static mt19937 gen(rd()); // популярный и высококачественный алгоритм генерации псевдослучайных чисел
    uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

// Функция заполнения массива случайными числами в заданном диапазоне
void fillArray(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; ++i) {
        arr[i] = randInt(min, max);
    }
}

// Функция вывода массива на экран
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функция сортировки пузырьком
void bubbleSort(int arr[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// Функция быстрой сортировки (сортировки Хоара)
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int p = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] > p) {
            i++;
        }
        while (arr[j] < p) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j) {
        quickSort(arr, left, j);
    }
    if (i < right) {
        quickSort(arr, i, right);
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    // Размеры массивов
    int sizes[] = { 10 };
    // Максимальное число в массиве В
    int maxB = 3;

    int* A = new int[10];
    fillArray(A, 10, 0, maxB * 2);

    printArray(A, 10);

    quickSort(A, 0, 10);

    printArray(A, 10);


    //for (int size : sizes) {
    //    // Заполнение массивов случайными числами
    //    int* B = new int[size];
    //    fillArray(B, size, 0, maxB);
    //    int* C = new int[size];
    //    int maxBValue = *max_element(B, B + size);

    //    // Формирование массива С из элементов массива А, которые меньше максимального элемента массива В
    //    int* it = copy_if(A, A + size, C, [maxBValue](int elem) { return elem < maxBValue; });
    //    int newSize = distance(C, it);

    //    // Сортировка массива С методом пузырька
    //    chrono::steady_clock::time_point begin = chrono::steady_clock::now(); // начало измерения времени
    //    chrono::steady_clock::time_point end = chrono::steady_clock::now(); // конец измерения времени
    //    cout << "Пузырьковая сортировка время на размер массива " << size << ": "
    //        << chrono::duration_cast<chrono::microseconds>(end - begin).count() << " микросекунд" << endl;


    //    // Сортировка массива С методом быстрой сортировки
    //    //begin = chrono::steady_clock::now(); // начало измерения времени
    //    //quickSort(C, 0, newSize - 1);
    //    //end = chrono::steady_clock::now(); // конец измерения времени
    //    //cout << "Быстрая сортировка время на размер массива " << size << ": "
    //    //    << chrono::duration_cast<chrono::microseconds>(end - begin).count() << " микросекунд" << endl;

    //    // Освобождаем выделенную память
    //    delete[] A;
    //    delete[] B;
    //    delete[] C;

    //    cout << endl;
    //}

    return 0;
}
