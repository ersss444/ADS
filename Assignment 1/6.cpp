#include <bits/stdc++.h>
using namespace std;

void reverseOfSequence(int n) {
    if(n == 0) {
        return;
    }

    char arr[21];
    cin.getline(arr, 21);

    reverseOfSequence(n - 1);

    cout << arr << "\n";
}

void solve() {
    int n; cin >> n;
    cin.ignore();

    reverseOfSequence(n);

}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
}