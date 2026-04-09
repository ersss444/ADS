#include <bits/stdc++.h>
using namespace std;

class HashTable {
    vector<list<int>> table;
    int size;
    int hashFunction(int key) { return key % size; }

public:
    HashTable(int s) { size = s; table.resize(size); }

    void insert(int key) { table[hashFunction(key)].push_back(key); }
    void remove(int key) { table[hashFunction(key)].remove(key); }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            for (int val : table[i]) cout << val << " -> ";
            cout << "NULL" << endl;
        }
    }

    int sum() {
        int total = 0;
        for (auto &bucket : table)
            for (int val : bucket) total += val;
        return total;
    }

    int getMax() {
        int maximum = numeric_limits<int>::min();
        for (auto &bucket : table)
            for (int val : bucket) if (val > maximum) maximum = val;
        return maximum;
    }

    int getMin() {
        int minimum = numeric_limits<int>::max();
        for (auto &bucket : table)
            for (int val : bucket) if (val < minimum) minimum = val;
        return minimum;
    }

    void displayEvenOdd() {
        cout << "Even: ";
        for (auto &bucket : table)
            for (int val : bucket) if (val % 2 == 0) cout << val << " ";
        cout << "\nOdd: ";
        for (auto &bucket : table)
            for (int val : bucket) if (val % 2 != 0) cout << val << " ";
        cout << endl;
    }
};

int main() {
    HashTable ht(10);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.insert(7);
    ht.insert(2);
    ht.insert(18);

    ht.display();
    cout << "Sum: " << ht.sum() << endl;
    cout << "Max: " << ht.getMax() << endl;
    cout << "Min: " << ht.getMin() << endl;
    ht.displayEvenOdd();

    ht.remove(25);
    ht.display();

    return 0;
}