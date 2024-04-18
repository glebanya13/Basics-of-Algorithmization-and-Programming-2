#include <iostream>
#include <Windows.h>

using namespace std;

int S(int x) {
    if (x > 100) {
        return x + 10;
    }
    else {
        return S(S(x + 4));
    }
}

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int x;
    cout << "Введите значение x: ";
    cin >> x;

    cout << "S(x) = " << S(x) << endl;

    return 0;
}