#include <iostream>
using namespace std;

struct Node {
    int key;
    string value;
    Node* left;
    Node* right;
};

class BinaryTree {
public:
    BinaryTree() {
        root = NULL;
    }

    // добавление узла в дерево
    void insert(int key, string value) {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;

        if (root == NULL) {
            root = newNode;
        }
        else {
            Node* current = root;
            Node* parent = NULL;
            while (true) {
                parent = current;
                if (key < current->key) {
                    current = current->left;
                    if (current == NULL) {
                        parent->left = newNode;
                        break;
                    }
                }
                else {
                    current = current->right;
                    if (current == NULL) {
                        parent->right = newNode;
                        break;
                    }
                }
            }
        }
    }

    // поиск узла в дереве
    Node* find(int key) {
        Node* current = root;
        while (current != NULL) {
            if (key == current->key) {
                return current;
            }
            else if (key < current->key) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return NULL;
    }

    // удаление узла из дерева
    bool remove(int key) {
        if (root == NULL) {
            return false;
        }

        Node* current = root;
        Node* parent = NULL;
        bool isLeftChild = true;

        while (current->key != key) {
            parent = current;
            if (key < current->key) {
                isLeftChild = true;
                current = current->left;
            }
            else {
                isLeftChild = false;
                current = current->right;
            }
            if (current == NULL) {
                return false;
            }
        }

        // если узел не имеет потомков
        if (current->left == NULL && current->right == NULL) {
            if (current == root) {
                root = NULL;
            }
            else if (isLeftChild) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
        }
        // если узел имеет только одного потомка
        else if (current->right == NULL) {
            if (current == root) {
                root = current->left;
            }
            else if (isLeftChild) {
                parent->left = current->left;
            }
            else {
                parent->right = current->left;
            }
        }
        else if (current->left == NULL) {
            if (current == root) {
                root = current->right;
            }
            else if (isLeftChild) {
                parent->left = current->right;
            }
            else {
                parent->right = current->right;
            }
        }
        // если узел имеет двух потомков
        else {
            Node* successor = getSuccessor(current);

            if (current == root) {
                root = successor;
            }
            else if (isLeftChild) {
                parent->left = successor;
            }
            else {
                parent->right = successor;
            }

            successor->left = current->left;
        }

        delete current;
        return true;
    }

    // функция для поиска преемника (следующего узла в порядке возрастания ключа)
    Node* getSuccessor(Node* d) {
        Node* sp = d;
        Node* successor = d;
        Node* current = d->right;

        while (current != NULL) {
            sp = successor;
            successor = current;
            current = current->left;
        }

        if (successor != d->right) {
            sp->left = successor->right;
            successor->right = d->right;
        }

        return successor;
    }

    // функция для определения количества узлов правой ветви дерева
    int countRightNodes() {
        if (root == NULL) {
            return 0;
        }

        Node* current = root;
        int count = 0;

        while (current != NULL) {
            if (current->right != NULL) {
                count += countNodes(current->right);
            }
            current = current->right;
        }

        return count;
    }
private:
    Node* root;
    // функция для определения количества узлов в поддереве
    int countNodes(Node* node) {
        if (node == NULL) {
            return 0;
        }
        else {
            return countNodes(node->left) + countNodes(node->right) + 1;
        }
    }
};

int main() {
    BinaryTree tree;
    // добавление узлов в дерево
    tree.insert(5, "value5");
    tree.insert(3, "value3");
    tree.insert(7, "value7");
    tree.insert(2, "value2");
    tree.insert(4, "value4");
    tree.insert(6, "value6");
    tree.insert(8, "value8");

    // определение количества узлов правой ветви дерева и вывод на экран
    int count = tree.countRightNodes();
    cout << "Number of nodes in the right subtree: " << count << endl;

    return 0;
}
