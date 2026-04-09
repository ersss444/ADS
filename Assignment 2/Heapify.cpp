#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;         // Изначально корень
    int left = 2 * i + 1;    // Левый ребёнок
    int right = 2 * i + 2;   // Правый ребёнок

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); 
    }
}


int main() {
    vector<int> arr = {4, 10, 3, 5, 1};

    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Max-Heap: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}