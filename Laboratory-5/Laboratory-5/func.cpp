#include "Header.h"

void push(struct Stack*& MyStack) {
	char chislo[9];
	cout << "��������: ";
	while (cin >> chislo && *chislo != 'q') { // *chislo - ������ ����� ������� chislo
		Stack* data = new Stack;
		data->number = atoi(chislo); // atoi - �������������� � ����� �����
		data->next = MyStack->head;
		MyStack->head = data;
	}
	return;
}

void clearStack(Stack*& MyStack) {
	if (!MyStack->head) { cout << "�����!\n"; }
	else {
		for (; MyStack->head; MyStack->head = MyStack->head->next) {} // for (�������������; �������; ��������� ���������)
		cout << "�������!\n"; // MyStack->head - ��������� �������� // MyStack->head = MyStack->head->next ���������� ��������� head �� ��������� ���� � �����
	}
}


void showStack(Stack*& MyStack) {
	Stack* data = MyStack->head;
	if (!MyStack->head) { cout << "�����\n"; }
	else { cout << "��������: \n"; }
	while (data) {
		cout << data->number << "\n"; // ���������� � ���� number �������� ���� �����
		data = data->next;
	}
}

void find(Stack* MyStack) {
	if (MyStack == nullptr || MyStack->head == nullptr || MyStack->head->next == nullptr) {
		// ���� ���� ��� �������� ������ ���� �������, ������ �� ������
		return;
	}

	Stack* current = MyStack->head;
	while (current != nullptr) {
		bool foundDuplicate = false;
		Stack* runner = current;
		while (runner->next != nullptr) {
			if (runner->next->number == current->number) {
				// ������ ������������� �������, ������� ���
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
		cout << "�����\n";
		return;
	}

	ofstream FILE(fileName);
	if (!FILE.is_open()) {
		cout << "�� ������� ������� ����\n";
		return;
	}

	Stack* current = MySt->head;
	while (current != nullptr) {
		FILE << current->number << " ";
		current = current->next;
	}

	FILE.close();
	cout << "�������� � ���� " << fileName << endl;
}

void ReadFromFile(Stack* MySt, string fileName) {
	int indicate;
	ifstream FILE(fileName);
	if (!FILE.is_open()) {
		cout << "�� ������� ������� ����\n";
		return;
	}

	while (FILE >> indicate) { // ��������� ����� �� ����� � ����������� ��� ���������� indicate.
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
	cout << "���������!\n";
}