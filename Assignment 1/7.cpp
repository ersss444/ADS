#include <bits/stdc++.h>
using namespace std;

void fillSpiral (vector<vector<int>> &arr, int sizeOfArray, int row, int col, int num) {
    if(sizeOfArray <= 0) {
        return;
    }
    if(sizeOfArray == 1) {
        arr[row][col] = num;
        return;
    }

    for(int i = 0; i < sizeOfArray - 1; i++) {
        arr[row][col + i] = num++;
    }

    for(int i = 0; i < sizeOfArray - 1; i++) {
        arr[row + i][col + sizeOfArray - 1] = num++;
    }

    for(int i = 0; i < sizeOfArray - 1; i++) {
        arr[row + sizeOfArray - 1][col + sizeOfArray - 1 - i] = num++;
    }

    for(int i = 0; i < sizeOfArray - 1; i++) {
        arr[row +sizeOfArray - 1 - i][col] = num++;
    }

    fillSpiral(arr, sizeOfArray - 2, row + 1, col + 1, num);
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    fillSpiral(arr, n, 0, 0, 1);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
}