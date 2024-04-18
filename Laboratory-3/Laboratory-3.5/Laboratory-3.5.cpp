#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

enum AccountType { SROCHNY, LYGOTNY, OTHER };
struct Date {
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 13;
};
struct Client {
    string fullName;
    AccountType accountType;
    int accountNumber;
    double balance;
    Date lastChangeDate;
};

void inputClientData(Client& client) {
    cout << "Введите Ф.И.О. клиента: ";
    cin.ignore();
    getline(cin, client.fullName);
    cout << "Выберите тип счета (0 - срочный, 1 - льготный, 2 - другой): ";
    int type;
    cin >> type;
    if (type == 0) {
        client.accountType = SROCHNY;
    }
    else if (type == 1) {
        client.accountType = LYGOTNY;
    }
    else {
        client.accountType = OTHER;
    }
    cout << "Введите номер счета: ";
    cin >> client.accountNumber;
    cout << "Введите сумму на счете: ";
    cin >> client.balance;
    cout << "Введите дату последнего изменения (день месяца год): ";
    int day1, month1, year1;
    cin >> day1 >> month1 >> year1;
    client.lastChangeDate.day = day1;
    client.lastChangeDate.month = month1;
    client.lastChangeDate.year = year1;
}

void displayClientData(const Client& client) {
    cout << "Ф.И.О.: " << client.fullName << endl;
    cout << "Тип счета: ";
    if (client.accountType == SROCHNY) {
        cout << "Срочный" << endl;
    }
    else if (client.accountType == LYGOTNY) {
        cout << "Льготный" << endl;
    }
    else {
        cout << "Другой" << endl;
    }
    cout << "Номер счета: " << client.accountNumber << endl;
    cout << "Сумма на счете: " << client.balance << endl;
    cout << "Дата последнего изменения: " << client.lastChangeDate.day << "." << client.lastChangeDate.month << "." << client.lastChangeDate.year << endl;
}

void deleteClient(Client clients[], int& numClients, int index) {
    if (index < 0 || index >= numClients) {
        cout << "Некорректный индекс клиента для удаления." << endl;
        return;
    }
    for (int i = index; i < numClients - 1; i++) {
        clients[i] = clients[i + 1];
    }
    numClients--;
    cout << "Клиент успешно удален." << endl;
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    const int MAX_CLIENTS = 100;
    Client clients[MAX_CLIENTS];
    int numClients = 0;
    int choice;

    do {
        cout << "\nМеню:\n1. Добавить клиента\n2. Вывести информацию о клиентах в заданном диапазоне суммы\n3. Удалить клиента\n0. Выход\nВыберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (numClients < MAX_CLIENTS) {
                inputClientData(clients[numClients]);
                numClients++;
            }
            else {
                cout << "Достигнуто максимальное количество клиентов." << endl;
            }
            break;
        case 2:
            double minAmount, maxAmount;
            cout << "Введите минимальную сумму для выбора клиентов: ";
            cin >> minAmount;
            cout << "Введите максимальную сумму для выбора клиентов: ";
            cin >> maxAmount;
            cout << "Клиенты с суммой на счете в диапазоне от " << minAmount << " до " << maxAmount << ":" << endl;
            for (int i = 0; i < numClients; i++) {
                if (clients[i].balance >= minAmount && clients[i].balance <= maxAmount) {
                    displayClientData(clients[i]);
                }
            }
            break;
        case 3:
            int clientIndex;
            cout << "Введите индекс клиента для удаления: ";
            cin >> clientIndex;
            deleteClient(clients, numClients, clientIndex);
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 0);

    return 0;
}
