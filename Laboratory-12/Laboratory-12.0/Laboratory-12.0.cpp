#include <iostream>

using namespace std;

struct HashNode {
    int key;
    int value;
    string name;
    HashNode* next;

    HashNode(int key, int value, string name) : key(key), value(value), name(name), next(nullptr) {}
};

struct Result {
    int value;
    string name;

    Result(int value, string name) : value(value), name(name) {}
};

class HashTable {
private:
    HashNode** table;
    int size;

    int hash(int key) {
        return key % size;
    }

public:
    HashTable(int size) : size(size) {
        table = new HashNode * [size]();
    }

    ~HashTable() {
        for (int i = 0; i < size; ++i) {
            HashNode* node = table[i];
            while (node != nullptr) {
                HashNode* next = node->next;
                delete node;
                node = next;
            }
        }
        delete[] table;
    }

    void put(int key, int value, string name) {
        int index = hash(key);
        HashNode* node = table[index];
        HashNode* prev = nullptr;

        while (node != nullptr) {
            if (node->key == key) {
                node->value = value;
                node->name = name;
                return;
            }
            prev = node;
            node = node->next;
        }

        HashNode* new_node = new HashNode(key, value, name);
        if (prev != nullptr) {
            prev->next = new_node;
        }
        else {
            table[index] = new_node;
        }
    }

    Result get(int key) {
        int index = hash(key);
        HashNode* node = table[index];
        while (node != nullptr) {
            if (node->key == key)
                return Result(node->value, node->name);
            node = node->next;
        }
        return Result(-1, "");
    }
};

void printHashTable(HashTable& table, int size) {
    for (int key = 1; key <= size; ++key) {
        Result result = table.get(key);
        cout << "Ключ " << key << ", Имя: "  << result.name << ", Номер места: " << result.value << endl;
    }
    cout << endl;
}

int main() {
	setlocale(LC_ALL, "RUS");
    HashTable table1(16);
    table1.put(1, 100, "Водитель1");
    table1.put(2, 150, "Водитель2");
    table1.put(3, 200, "Водитель3");
    table1.put(4, 300, "Водитель4");
    table1.put(5, 400, "Водитель5");
    

    HashTable table2(32);
    table2.put(1, 100, "Водитель1");
    table2.put(2, 200, "Водитель2");
    table2.put(3, 300, "Водитель3");
    table2.put(4, 400, "Водитель4");

    printHashTable(table1, 5);
    printHashTable(table2, 4);

    return 0;
}
