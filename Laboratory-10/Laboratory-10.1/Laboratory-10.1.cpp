#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <iomanip>

using namespace std;

struct Node
{
    int data;
    Node* left = nullptr, * right = nullptr;
};

Node* insert(Node* root, int key)
{
    // if root is null, create a new node and return it
    if (root == nullptr)
        return new Node{ key };

    // if given key is less than root node's key, repeat for left subtree
    if (key < root->data)
        root->left = insert(root->left, key);

    // if given key is greater than root node's key, repeat for right subtree
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

void printLevelOrderTraversal(Node* root)
{
    int probel = 20;
    std::cout << '\n';

    // base case: empty tree
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            std::cout << std::setw(probel + 10) << std::setfill(' ') << " ";
            Node* front = q.front();
            q.pop();

            std::cout << front->data << ' ';

            if (front->left)
                q.push(front->left);

            if (front->right)
                q.push(front->right);

            probel /= 2;
        }
        std::cout << endl;
    }
}

void inorder(Node* root, queue<int>& keys)
{
    if (root == nullptr)
        return;

    inorder(root->left, keys);
    keys.push(root->data);
    inorder(root->right, keys);
}

void preorder(Node* root, queue<int>& keys)
{
    // base case: empty tree
    if (root == nullptr)
        return;

    // replace root node's value with next key from queue
    root->data = keys.front();
    keys.pop();

    // traverse left subtree
    preorder(root->left, keys);

    // traverse right subtree
    preorder(root->right, keys);
}

void convert(Node* root)
{
    // base case: empty tree
    if (root == nullptr)
        return;

    // create a queue to store the level-order traversal of the tree
    queue<int> keys;

    // perform level-order traversal and store keys in the queue
    inorder(root, keys);

    // traverse the tree in pre-order and assign each key to its node
    preorder(root, keys);
}

int main()
{
    setlocale(LC_ALL, "rus");
    vector<int> keys = { 15, 18, 9, 10, 8, 19, 17 };    // vector of values that will form the tree and heap

    cout << "Converting tree with values: ";
    Node* root = nullptr;
    for (int key : keys)
    {
        cout << key << " ";
        root = insert(root, key);
    }

    convert(root);
    printLevelOrderTraversal(root);

    return 0;
}