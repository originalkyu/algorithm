#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int n = 10;
    int arr[n][n];
    int temp[n][n];

    int val=1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            arr[i][j] = val++;
        }
    }

    memcpy(temp, arr, sizeof(arr));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << temp[i][j] << " ";
        }
        cout << "\n";
    }
}