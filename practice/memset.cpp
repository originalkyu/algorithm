/*
memset 은 배열을 0으로 초기화할 때 이용한다.
*/

#include <iostream>
#include <cstring> // memset
using namespace std;

int main() {
    const int n = 10;
    int arr[n][n];

    cout << "sizeof(arr): " << sizeof(arr) << "\n";
    
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "--------------\n\n";

    memset(arr, 3, sizeof(arr));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "--------------\n\n";
}