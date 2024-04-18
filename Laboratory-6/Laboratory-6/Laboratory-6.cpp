// Вариант 15
#include <iostream>
#include <queue> // стандартный контейнер очереди

using namespace std;

// Функция для ввода символа в очередь
void enqueueSymbol(queue<char>& q, char etalon) { // функция принимает ссылку на очередь символов и символ-эталон
    char symbol;
    cout << "Введите символ: ";
    cin >> symbol;

    q.push(symbol);

    if (symbol == etalon) {
        // Удаляем два элемента, если встретился эталонный символ
        q.pop();
        q.pop();
    }
}

// Функция для вывода очереди
void displayQueue(const queue<char>& q) {
    cout << "Очередь: ";
    queue<char> tempQueue = q;  // Создаем временную копию для вывода (без изменения оригинала)
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;
}

// Функция для удаления элемента из очереди
void dequeueSymbol(queue<char>& q) {
    if (!q.empty()) {
        cout << "Удален символ: " << q.front() << endl;
        q.pop();
    }
    else {
        cout << "Очередь пуста." << endl;
    }
}

// Функция для определения размера очереди
void queueSize(const queue<char>& q) {
    cout << "Размер очереди: " << q.size() << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    queue<char> symbolQueue;
    char etalon;

    // Ввод эталонного символа
    cout << "Введите эталонный символ: ";
    cin >> etalon;

    int choice;
    do {
        // Меню
        cout << "\nМеню:\n";
        cout << "1. Ввод символа в очередь\n";
        cout << "2. Вывод очереди\n";
        cout << "3. Удаление символа из очереди\n";
        cout << "4. Размер очереди\n";
        cout << "0. Выход\n";
        cout << "Выберите операцию: ";
        cin >> choice;

        switch (choice) {
        case 1:
            enqueueSymbol(symbolQueue, etalon);
            break;

        case 2:
            displayQueue(symbolQueue);
            break;

        case 3:
            dequeueSymbol(symbolQueue);
            break;

        case 4:
            queueSize(symbolQueue);
            break;

        case 0:
            cout << "Программа завершена." << endl;
            break;

        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
