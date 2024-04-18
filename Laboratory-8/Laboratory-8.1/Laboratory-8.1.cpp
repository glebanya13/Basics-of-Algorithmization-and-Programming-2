#include <iostream>
#include <Windows.h>
using namespace std;

int countPartitions(int m, int n) {
    if (m == 0 || n == 0 || m == 1)
        return 1;

    if (m < 0 || n < 0)
        return 0;

    return countPartitions(m, n - 1) + countPartitions(m - n, n);
}
int countPartitions(int m) {
    return countPartitions(m, m);
}

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int m = 4;
    cout << "Количество разбиений числа " << m << " равно: " << countPartitions(m) << endl;
    return 0;
}
