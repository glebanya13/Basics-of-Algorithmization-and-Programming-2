// variant 7
#include "Header.h"

void menu() {
	cout << "0) Выход из приложения\n1) Запись чисел в стек\n" <<
		"2) Вывод стека\n3) Очистка стека\n4) Задание из варианта"
		<< "\n5) Запись стека в файл\n6)Считать стек из файла\nВаш выбор: ";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int number, vibor;
	Stack* MyStack1 = new Stack;

	MyStack1->head = nullptr;

	while (true) {
		menu();
		cin >> vibor;
		switch (vibor) {
		case 0: return 0;
		case 1:
			cout << "\nДля завершения введите q\n";
			cout << "Введите элементы стека:" << endl;
			push(MyStack1);
			break;
		case 2:
			cout << "Элементы первого стека:" << endl;
			showStack(MyStack1);
			break;
		case 3:
			clearStack(MyStack1);
			break;
		case 4: find(MyStack1);
			break;
		case 5:
			WriteInFile(MyStack1, "Data1.txt");
			break;
		case 6:
			cout << "Элементы первого стека:" << endl;
			ReadFromFile(MyStack1, "Data1.txt");
			showStack(MyStack1);
			break;
		}
	}
}