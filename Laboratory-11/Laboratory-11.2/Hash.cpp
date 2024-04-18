#include "Hash.h"
#include <iostream>

int HashFunction(int key, int size, int p) // ��� �������
{
	double A;
	A = (sqrt(5.0f) - 1.0f) / 2.0f;
	int k;
	k = key * A;
	return k % size;
}

//-------------------------------
int Next_hash(int hash, int size, int p)
{
	return  (hash + 5 * p + 3 * p * p) % size;
}
//-------------------------------
Object create(int size, int(*getkey)(void*)) // ��������
{
	return *(new Object(size, getkey));
}
//-------------------------------
Object::Object(int size, int(*getkey)(void*)) // ��������
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}
//-------------------------------
bool Object::insert(void* d) // �������
{
	bool b = false;
	if (N < size / 2)
		for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0); i != size && !b; j = Next_hash(j, size, ++i))
			if (data[j] == NULL || data[j] == DEL)
			{
				data[j] = d;
				N++;
				b = true;
			}
	if (!b && N >= size / 2)
	{
		int newSize = size * 2;
		Object newObject = create(newSize, getKey);
		for (int i = 0; i < size; ++i) {
			if (data[i] != NULL && data[i] != DEL) {
				newObject.insert(data[i]);
			}
		}

		for (int i = 0, t = getKey(d), j = HashFunctionU(t, newSize, 0); i != newSize && !b; j = Next_hash(j, newSize, ++i)) {
			if (newObject.data[j] == NULL || newObject.data[j] == DEL) {
				newObject.data[j] = d;
				newObject.N++;
				b = true;
			}
		}
	}
	return b;
}
//-------------------------------
int Object::searchInd(int key) // �����
{
	int t = -1;
	bool b = false;
	if (N != 0)
		for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i != size && !b; j = HashFunction(key, size, ++i)) // ??????????? ????? 
			if (data[j] != DEL)
				if (getKey(data[j]) == key)
				{
					t = j; b = true;
				}
	return t;
}
//-------------------------------
void* Object::search(int key)
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
//-------------------------------
void* Object::deleteByKey(int key) // �������� �� �����
{
	int i = searchInd(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
//-------------------------------
bool Object::deleteByValue(void* d) // �������� �� ��������
{
	return(deleteByKey(getKey(d)) != NULL);
}
//-------------------------------
void Object::scan(void(*f)(void*)) // �����
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " ������� " << i;
		if ((this->data)[i] == NULL)
			std::cout << "  �����" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  ������ " << std::endl;
			else
				f((this->data)[i]);
	}
}
int HashFunctionU(int key, int size, int p) // f ���������� ��� 50%
{
	int h, a = 31415, b = 27183;
	for (h = 0; key != 0; key--, a = a * b % (size - 1))
		h = (a * h + key) % size;
	return (h < 0) ? (h + size) : h;
}
