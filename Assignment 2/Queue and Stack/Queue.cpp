#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node* next;

    Node(T value) {
        this->value = value;
        next = nullptr;
    }
};

template<typename T>
class Queue {
    Node<T>* frontNode;
    Node<T>* rearNode;

public:
    Queue() {
        frontNode = rearNode = nullptr;
    }

    bool empty() {
        return rearNode == nullptr;
    }

    void enqueue(T value) {
        Node<T>* newNode = new Node(value);
        if(rearNode == nullptr) {
            frontNode = rearNode = newNode;
            return;
        }

        rearNode->next = newNode;
        rearNode = newNode;
    }

    void dequeue() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node<T>* temp = frontNode;
        frontNode = frontNode->next;
        if (frontNode == nullptr) rearNode = nullptr; //
        delete temp;
    }

    T front() {
        if (empty()) {
            throw runtime_error("Queue is empty");
        }
        return frontNode->value;
    }

    void print() {
        Node<T>* temp = frontNode;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void clear() {
        while (!empty()) {
            dequeue();
        }
    }

};

template <typename T>
void removeEven(Queue<T>& q) {
    Queue<T> temp;

    while (!q.empty()) {
        T val = q.front();
        q.dequeue();

        if (val % 2 != 0) { 
            temp.enqueue(val);
        }
    }

    while (!temp.empty()) {
        q.enqueue(temp.front());
        temp.dequeue();
    }
}

void solve() {
    Queue<int> q;

    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(20);
    q.enqueue(40);
    q.enqueue(60);

    q.print();

    removeEven(q);

    q.print();

}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
}
