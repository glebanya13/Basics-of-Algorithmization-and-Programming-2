#include "Header.h"

void push(struct Stack*& MyStack) {
	char chislo[9];
	cout << "Элементы: ";
	while (cin >> chislo && *chislo != 'q') { // *chislo - первое число массива chislo
		Stack* data = new Stack;
		data->number = atoi(chislo); // atoi - преобразование в целое число
		data->next = MyStack->head;
		MyStack->head = data;
	}
	return;
}

void clearStack(Stack*& MyStack) {
	if (!MyStack->head) { cout << "Пусто!\n"; }
	else {
		for (; MyStack->head; MyStack->head = MyStack->head->next) {} // for (инициализация; условие; выражение изменения)
		cout << "Успешно!\n"; // MyStack->head - начальное значение // MyStack->head = MyStack->head->next перемещает указатель head на следующий узел в стеке
	}
}


void showStack(Stack*& MyStack) {
	Stack* data = MyStack->head;
	if (!MyStack->head) { cout << "Пусто\n"; }
	else { cout << "Элементы: \n"; }
	while (data) {
		cout << data->number << "\n"; // обращается к полю number текущего узла стека
		data = data->next;
	}
}

void find(Stack* MyStack) {
	if (MyStack == nullptr || MyStack->head == nullptr || MyStack->head->next == nullptr) {
		// Стек пуст или содержит только один элемент, ничего не делаем
		return;
	}

	Stack* current = MyStack->head;
	while (current != nullptr) {
		bool foundDuplicate = false;
		Stack* runner = current;
		while (runner->next != nullptr) {
			if (runner->next->number == current->number) {
				// Найден повторяющийся элемент, удаляем его
				Stack* delStack = runner->next;
				runner->next = runner->next->next;
				delete delStack;
				foundDuplicate = true;
				break;
			}
			runner = runner->next;
		}
		if (foundDuplicate) {
			break;
		}
		current = current->next;
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
	int indicate;
	ifstream FILE(fileName);
	if (!FILE.is_open()) {
		cout << "Не удалось открыть файл\n";
		return;
	}

	while (FILE >> indicate) { // считывает число из файла и присваивает его переменной indicate.
		Stack* data = new Stack;
		data->number = indicate;
		data->next = nullptr;

		if (MySt->head == nullptr) {
			MySt->head = data;
		}
		else {
			Stack* current = MySt->head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = data;
		}
	}

	FILE.close();
	cout << "Прочитано!\n";
}