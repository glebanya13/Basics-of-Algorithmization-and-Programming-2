#include <iostream>
#include <vector>

using namespace std;

// Функция для печати всех перестановок
void printPermutations(vector<int>& nums, int start, int end) {
    if (start == end) {
        // Выводим текущую перестановку
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= end; i++) {
        // Меняем местами элементы start и i
        swap(nums[start], nums[i]);

        // Рекурсивно генерируем перестановки для оставшихся элементов
        printPermutations(nums, start + 1, end);

        // Возвращаем исходную перестановку
        swap(nums[start], nums[i]);
    }
}

int main() {
    vector<int> nums = { 1, 2, 3, 4, 5 };
    int n = nums.size();

    printPermutations(nums, 0, n - 1);

    return 0;
}
