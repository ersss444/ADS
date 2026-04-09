#include <bits/stdc++.h>
using namespace std;

int sumOfArray(int arr[], int n) {
    if(n == 0) {
        return 0;
    }

    return arr[n - 1] + sumOfArray(arr, n - 1);
}

void solve() {
    int sizeOfArray; cin >> sizeOfArray;
    int arr[sizeOfArray]; 

    for(int i = 0; i < sizeOfArray; i++) {
        cin >> arr[i];
    }

    int n; cin >> n;

    cout << sumOfArray(arr, n) << "\n";
}

int main() {
    int t = 1; 
    while(t--) {
        solve();
    }
}