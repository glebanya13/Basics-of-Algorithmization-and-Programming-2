#include "Heap.h"
#include <iostream>
using namespace std;
heap::CMP cmpAAA(void* a1, void* a2)  //Функция сравнения
{
#define A1 ((AAA*)a1) // функции
#define A2 ((AAA*)a2) 
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(30, cmpAAA);


	for (;;)
	{
		int choisebuff;
		cout << "1 - вывод кучи на экран" << endl;
		cout << "2 - добавить элемент" << endl;
		cout << "3 - удалить максимальный элемент" << endl;
		cout << "4 - удаление минимального" << endl;
		cout << "5 - удалить i-того" << endl;
		cout << "6 - вставка в 2 дерево" << endl;
		cout << "7 - вывод в 2 дерева" << endl;
		cout << "8 - слияние" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;  cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1:  h1.scan(0);
			break;
		case 2: {	AAA* a = new AAA;
			cout << "введите ключ" << endl; 	cin >> k;
			a->x = k;
			h1.insert(a);
		}
			  break;
		case 3:   h1.extractMax(); break;

		case 4:   h1.extractMin(); break;

		case 5:cin >> choisebuff; h1.extractIth(choisebuff); break;

		case 6: {	AAA* a = new AAA;
			cout << "введите ключ" << endl; 	cin >> k;
			a->x = k;
			h2.insert(a);

		}
			  break;
		case 7:  h2.scan(0); break;
		case 8:h1.mergeHeaps(h2); break;
			break;
		default:  cout << endl << "Введена неверная команда!" << endl;
		}
	} return 0;
}