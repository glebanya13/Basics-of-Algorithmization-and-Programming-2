#include <iostream>
#include <fstream>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};
//-----------------------------------------------------------
int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. Ввод имени" << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Запись в файл" << endl;
	cout << "6. Прочитать с файла" << endl;
	cout << "7. Добавление в конец другого списка" << endl;
	cout << "8. Выход" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin.sync(); // - очистка буфера ввода
		gets_s(s); // - считывание строки в массив s
		cout << endl;
		c = atoi(s); // - преобразование строки в число и сохранение его в переменную c
	} while (c < 0 || c > 8);
	return c;
}
//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{ // - указатели на указатели используются здесь, чтобы функция могла изменить значения указателей phead и plast в вызывающей функции
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement() // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail()); // - сбрасывает флаги ошибок ввода-вывода после считывания имени
	cin.clear(); // очищает входной буфер
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
Address* setElements() // Создание элемента и ввод его значений с клавиатуры 
{
	int choice;
	cout << "Введите кол-во элементов списка: ";
	cin >> choice;

	Address* head = nullptr; // Голова списка
	Address* tail = nullptr; // Хвост списка

	for (int i = 0; i < choice; ++i) {
		Address* temp = new Address();
		if (!temp)
		{
			cerr << "Ошибка выделения памяти";
			return nullptr;
		}

		cout << "Введите имя: ";
		cin.ignore(); // Игнорируем символ новой строки во входном буфере
		cin.getline(temp->name, NAME_SIZE - 1, '\n');

		cout << "Введите город: ";
		cin.getline(temp->city, CITY_SIZE - 1, '\n');

		temp->next = nullptr;
		temp->prev = nullptr;

		if (head == nullptr) {
			// Если это первый элемент, устанавливаем его как голову списка
			head = temp;
			tail = temp;
		}
		else {
			// Иначе добавляем элемент в конец списка
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
	}

	return head; // Возвращаем указатель на голову списка
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break; // сравнение имени, переданного в функцию, с именем текущего элемента списка
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление имени
{
	struct Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name))  break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
	}
}
//-----------------------------------------------------------
void writeToFile(Address** phead)       //Запись в файл
{
	struct Address* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "wb"); // открывает файл с именем "mlist" в режиме записи двоичных данных ("wb")
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp); // записывается один элемент структуры размером
		t = t->next;
	}
	fclose(fp); // после прохода по всем элементам списка, файл закрывается
}
//-----------------------------------------------------------
void readFromFile(Address** phead, Address** plast)   //Считывание из файла
{
	struct Address* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "rb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	while (*phead) // - удаляет все элементы из списка, пока список не станет пустым
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL; // после удаления всех элементов, указатели на начало и конец списка устанавливаются в значение NULL.
	cout << "Загрузка из файла" << endl;
	while (!feof(fp)) // Этот цикл будет выполняться до тех пор, пока не достигнут конец файла.
	{
		t = new Address();
		if (!t)
		{
			cerr << "Ошибка выделения памяти" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
		// Если не удалось прочитать один элемент структуры Address из файла, цикл прерывается.
		insert(t, phead, plast);
	}
	fclose(fp);
}
//-----------------------------------------------------------
void addLEnd(Address** phead, Address** plast, Address* L) {
	if (L == nullptr) {
		return; // Если список L пуст, завершаем функцию
	}

	Address* current = L;

	while (current != nullptr) {
		Address* t = new Address(); // Создаем новый узел для каждого элемента списка L
		strcpy_s(t->name, current->name); // Копируем данные из списка L в новый узел
		strcpy_s(t->city, current->city);
		t->next = nullptr;

		if (*phead == nullptr) {
			*phead = t; // Если список пустой, новый узел становится началом списка
		}
		else {
			(*plast)->next = t; // Добавляем новый узел в конец списка
		}
		t->prev = *plast;
		*plast = t; // Обновляем указатель на последний элемент списка

		current = current->next; // Переходим к следующему элементу списка L
	}
}
//-----------------------------------------------------------
int main(void)
{
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2: {	  char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
		}
			  break;
		case 3:  outputList(&head, &last);
			break;
		case 4: {	  char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
		}
			  break;
		case 5:
			writeToFile(&head);
			exit(0);
		case 6:
			readFromFile(&head, &last);
			break;
		case 7:
			addLEnd(&head, &last, setElements());
			break;
		default:
			exit(1);
		}
	}
	return 0;
}
