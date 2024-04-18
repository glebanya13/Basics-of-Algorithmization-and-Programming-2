#include <iostream>
#include <fstream>

using namespace std;

// Структура для узла списка
struct Node {
    int data;   // данные узла
    Node* next; // указатель на следующий узел
};

// Глобальный указатель на начало списка
Node* head = nullptr;

// Функция для добавления элемента в начало списка
void addElement(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Функция для удаления элемента по значению
void deleteElement(int value) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (previous != nullptr) {
            previous->next = current->next;
        }
        else {
            head = current->next;
        }
        delete current;
    }
}

// Функция для поиска элемента в списке
bool searchElement(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Функция для вывода списка в консольное окно
void displayList() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Функция для записи списка в файл
void writeToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        file << current->data << " ";
        current = current->next;
    }

    file.close();
    cout << "List written to file successfully." << endl;
}

// Функция для считывания списка из файла
void readFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    int value;
    while (file >> value) {
        addElement(value);
    }

    file.close();
}

// Функция для поиска суммы
int sumOf() {
    bool IsExist = false;
    int sum = 0;
    Node* current = head;
    while (current != nullptr) {
        if (current->data % 10 == 7) {
            sum += current->data;
            IsExist = true;
        }
        current = current->next;
    }
    if (!IsExist) {
        cout << "There are no elements...";
    }
    return sum;
}

int main() {
    char choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Search element" << endl;
        cout << "4. Display list" << endl;
        cout << "5. Write to file" << endl;
        cout << "6. Read from file" << endl;
        cout << "7. Find sum" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            int value;
            cout << "Enter value to add: ";
            cin >> value;
            addElement(value);
            break;
        }
        case '2': {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            deleteElement(value);
            break;
        }
        case '3': {
            int value;
            cout << "Enter value to search: ";
            cin >> value;
            if (searchElement(value)) {
                cout << "Element found." << endl;
            }
            else {
                cout << "Element not found." << endl;
            }
            break;
        }
        case '4':
            cout << "List: ";
            displayList();
            break;
        case '5': {
            string filename;
            cout << "Enter filename to write to: ";
            cin >> filename;
            writeToFile(filename);
            break;
        }
        case '6': {
            string filename;
            cout << "Enter filename to read from: ";
            cin >> filename;
            readFromFile(filename);
            cout << "List read from file." << endl;
            break;
        }
        case '7':
            cout << "Sum of what we need: " << sumOf() << endl;

            break;
        case '8':
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '8');

    return 0;
}