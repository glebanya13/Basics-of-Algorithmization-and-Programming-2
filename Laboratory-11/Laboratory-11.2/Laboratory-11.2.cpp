// dop 12

#include "Hash.h"
#include <iostream>
using namespace std;
struct AAA // узел
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;  mas = z;
	} AAA() {}
};
//-------------------------------
int key(void* d) // ключ
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(void* d) // вывод
{
	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int siz = 16, choice, k;
	cout << "Введите размер хеш-таблицы" << endl; 	cin >> siz;
	Object H = create(siz, key);
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;   cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: H.scan(AAA_print);

			break;
		case 2: { AAA* a = new AAA;
			char* str = new char[20];
			cout << "введите ключ" << endl;	cin >> k;
			a->key = k;
			cout << "введите строку" << endl; cin >> str;
			a->mas = str;
			cout << H.N << " " << H.size << endl;

			if ((double)H.N > ((double)(H.size) * 0.5F)) // 12 вариант // if ((double)H.N > (double)(H.size) * 0.7) ----- 14 вариант
			{
				cout << "Таблица заполнена на 50%(50% = " << ((double)(H.size) * 0.5) << " количество элементов в таблице " << H.N << ") Расширяется в 2 раза" << endl;
				Object H1 = create(H.size * 2, key); //	Object H1 = create(H.size*3, key); ------ 14 вариант
				for (int i = 0; i < H.size; i++)
				{
					H1.data[i] = H.data[i];
				}
				H1.N = H.N;
				H1.insert(a);
				H = H1;
			}
			else
				H.insert(a);
		} break;
		case 3: {  cout << "введите ключ для удаления" << endl;
			cin >> k;
			H.deleteByKey(k);
		}  break;
		case 4: {  cout << "введите ключ для поиска" << endl;
			cin >> k;
			if (H.search(k) == NULL)
				cout << "Элемент не найден" << endl;
			else
				AAA_print(H.search(k));
		}  break;
		}
	}
	return 0;
}