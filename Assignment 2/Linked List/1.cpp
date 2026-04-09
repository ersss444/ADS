#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node *next;
    
    Node(int value, Node *next) {
        this->value = value;
        this->next = next;
    }
};

class LinkedList {
    Node *head;
    int sz;

public:
    LinkedList() {
        head = nullptr;
        sz = 0;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }

    void push_front(int val) {
        head = new Node(val, head);
        sz++;
    }

    void push_back(int val) {
        if(head == nullptr) {
            head = new Node(val, nullptr);
            sz++;
            return;
        }

        Node* cur = head;
        while(cur->next != nullptr) {
            cur = cur->next;
        }

        cur->next = new Node(val, nullptr);
        sz++;
    }

    void pop_back() {
        if(head == nullptr) {
            return;
        }

        if(head->next == nullptr) {
            delete head;
            head = nullptr;
            sz--;
            return;
        }

        Node* cur = head;
        while(cur->next->next != nullptr) {
            cur = cur->next;
        }

        delete cur->next;
        cur->next = nullptr;
    }

    void print() {
        Node* cur = head;

        while(cur != nullptr) {
            cout << cur->value << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    Node* findNode(int val) {
        Node* cur = head;

        while(cur != nullptr) {
            if(cur->value == val) {
                return cur;
            }

            cur = cur->next;
        }

        return nullptr;
    }

    void insert(int index, int val) {
        if(index == 0) {
            push_front(val);
            return;
        }

        if(index < 0 || index > sz) {
            return;
        }

        Node* cur = head;

        for(int i = 0; i < index - 1; i++) {
            cur = cur->next;
        }

        Node *newNext = new Node(val, cur->next);
        cur->next = newNext;
        sz++;

    }

    void remove(int val) {
        if(head == nullptr) return;

        if(head->value == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            sz--;
            return;
        }

        Node* cur = head;
        while(cur->next != nullptr) {
            if(cur->next->value == val) {
                Node* temp = cur->next;
                cur->next = temp->next;
                delete temp;
                sz--;
                return;
            }
            cur = cur->next;
        }
    }

    void merge(LinkedList &other) {

        if(&other == this) {
            return;
        }

        if(head == nullptr) {
            head = other.head;
            sz = other.sz;

            other.head = nullptr;
            other.sz = 0;

            return;
        }

        Node *cur = head;
        while(cur->next != nullptr) {
            cur = cur->next; 
        }

        cur->next = other.head;
        sz += other.sz;

        other.head = nullptr;
        other.sz = 0;

        return;
    }

    void reverse() {
        Node *prev = nullptr;
        Node *cur = head;
        Node *next = nullptr;

        while(cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next; 
        }

        head = prev;
    }

    void sort() {
        if(!head || !head->next) {
            return;
        }

        Node *i = head;
        while(i != nullptr) {
            Node *j = i->next;
            while(j != nullptr) {
                if(i-> value > j->value) {
                    swap(i->value, j->value);
                }
                j = j->next;
            }
            i = i->next;
        }
    }

};

void solve() {

    LinkedList list1, list2;

    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    list2.push_back(4);
    list2.push_back(5);
    list2.push_back(6);

    list1.reverse();


    list1.print();

    list1.insert(1, 5);

    list1.remove(2);

    list1.merge(list2);

    list1.sort();

    list1.print();



    cout << list1.findNode(1)->value << endl;;

}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
}