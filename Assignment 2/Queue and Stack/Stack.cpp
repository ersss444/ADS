#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Node {
    T value;
    Node* next;

    Node(T value) {
        this->value = value;
        next = nullptr;
    }
};


template <typename T>
class Stack {
    Node<T>* head;

public:
    Stack() {
        head = nullptr;
    }

    bool empty() {
        return head == nullptr;
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (empty()) {
            cout << "Stack is empty\n";
            return;
        }

        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    T top() {
        if (empty()) {
            throw runtime_error("Stack is empty");
        }
        return head->value;
    }

    void print() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void clear() {
        while(!empty()) {
            pop();
        }
    }

};

void removeLessThanAVG(Stack<double>& st) {
    Stack<double> temp;
    double sum = 0;
    int size = 0;

    while(!st.empty()) {
        temp.push(st.top());
        sum += st.top();
        size += 1;
        st.pop();
    }

    double avg = sum / size;

    while(!temp.empty()) {
        if(temp.top() >= avg) {
            st.push(temp.top());
        }
        temp.pop();
    }
}

void solve() {

    Stack<double> st;

    st.push(1.6);
    st.push(1.7);
    st.push(1.8);
    st.push(1.9);
    st.push(2.0);

    removeLessThanAVG(st);

    st.print();

}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
}