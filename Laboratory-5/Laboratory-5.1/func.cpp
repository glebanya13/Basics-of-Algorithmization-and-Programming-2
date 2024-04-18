#include "Header.h"
void push(struct Stack*& MyStack) {
    char chislo[9];
    cout << "Элементы: "; 
    while (cin >> chislo && *chislo != 'q') {
        Stack* data = new Stack;  
        data->number = atoi(chislo);
        data->next = MyStack->head;  
        MyStack->head = data;
    } 
    return;
}
void clearStack(Stack*& MyStack) {
    if (!MyStack->head) { cout << "Пусто!\n"; }
    else {
        for (; MyStack->head; MyStack->head = MyStack->head->next) {}
        cout << "Успешно!\n";
    }
}
void showStack(Stack*& MyStack) {
    Stack* data = MyStack->head; 
    if (!MyStack->head) { cout << "Пусто\n"; }
    else { cout << "Элементы: \n"; } 
    while (data) {
        cout << data->number << "\n";  
        data = data->next;
    }
}
void find(Stack* MySt1, Stack* MySt2, Stack* MySt3) {
    if (!MySt1->head) { cout << "Пусто!\n"; }
    else if (!MySt2->head) { cout << "Пусто!\n"; }
    else {
        Stack* MyStack1 = new Stack;
        Stack* MyStack2 = new Stack;  
        MyStack1->head = MySt1->head;
        MyStack2->head = MySt2->head;  
        int b[20], a[20];
        int n = 0, r = 0;  
        while (MyStack1->head) {
            a[n] = MyStack1->head->number;   
            MyStack1->head = 
                MyStack1->head->next;
            n++;
        }
        while (MyStack2->head) {
            b[r] = MyStack2->head->number;
            MyStack2->head = MyStack2->head->next;   
            r++;
        }
        int c[20];  
        int k = 0, l = 0;
        for (int i = 0; i < n; i++) {
            bool found = false;    
            for (int j = 0; j < r; j++) {
                if (a[i] == b[j]) {
                    found = true;
                    break;
                }
            }   if (!found) {
                c[k] = a[i];   
                k++;
            }
        }

        for (int i = k - 1; i > -1; i--) {
            Stack* data = new Stack;
            data->number = c[i];   
            data->next = MySt3->head;
            MySt3->head = data;
        }
    }
}
void WriteInFile(Stack* MySt, string fileName) {
    if (!MySt->head) {
        cout << "Пусто\n";
        return;
    }
    ofstream FILE(fileName);
    if (!FILE.is_open()) {
        cout << "Не удалось открыть файл\n";
        return;
    }
    Stack* current = MySt->head;
    while (current != nullptr) {
        FILE << current->number << " ";
        current = current->next;
    }

    FILE.close();
    cout << "Записано в файл " << fileName << endl;
}
void ReadFromFile(Stack* MySt, string fileName) {
    int indicate; ifstream FILE(fileName);
    if (!FILE.is_open()) {
        cout << "Не удалось открыть файл\n";
        return;
    }
    while (FILE >> indicate) {
        Stack* data = new Stack;  data->number = indicate;
        data->next = nullptr;
        if (MySt->head == nullptr) {
            MySt->head = data;
        }
        else {
            Stack* current = MySt->head;   while (current->next != nullptr) {
                current = current->next;
            }
            current->next = data;
        }
    }
    FILE.close();
    cout << "Прочитано!\n";
}
