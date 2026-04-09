#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    }

    Node* minValueNode(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (!node) return node;
        if (key < node->data) node->left = deleteNode(node->left, key);
        else if (key > node->data) node->right = deleteNode(node->right, key);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void countEvenOdd(Node* node, int &even, int &odd) {
        if (!node) return;
        if (node->data % 2 == 0) even++;
        else odd++;
        countEvenOdd(node->left, even, odd);
        countEvenOdd(node->right, even, odd);
    }

    int findMin(Node* node) {
        if (!node) return INT_MAX;
        return min(node->data, min(findMin(node->left), findMin(node->right)));
    }

    int findMax(Node* node) {
        if (!node) return INT_MIN;
        return max(node->data, max(findMax(node->left), findMax(node->right)));
    }

    int height(Node* node) {
        if (!node) return 0;
        return max(height(node->left), height(node->right)) + 1;
    }

    void deleteTree(Node* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() { deleteTree(root); }

    void insert(int val) { root = insert(root, val); }
    void remove(int val) { root = deleteNode(root, val); }
    void display() {
        inorder(root);
        cout << endl;
    }
    void countEvenOdd() {
        int even = 0, odd = 0;
        countEvenOdd(root, even, odd);
        cout << "Even: " << even << ", Odd: " << odd << endl;
    }
    void showMinMax() {
        cout << "Min: " << findMin(root) << ", Max: " << findMax(root) << endl;
    }
    void showHeight() {
        cout << "Height: " << height(root) << endl;
    }
    bool isEmpty() { return root == nullptr; }
};

int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(15);
    tree.insert(8);

    tree.display();
    tree.countEvenOdd();
    tree.showMinMax();
    tree.showHeight();
    cout << (tree.isEmpty() ? "Tree is empty" : "Tree is not empty") << endl;

    tree.remove(10);
    tree.display();
    tree.countEvenOdd();
    tree.showMinMax();
    tree.showHeight();

    return 0;
}