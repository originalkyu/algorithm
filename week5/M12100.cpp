/*
https://www.acmicpc.net/problem/12100
*/
#include <iostream>
#include <cstring> // memcpy()
#include <algorithm> // max()
using namespace std;


int n;
struct Board {
    int a[22][22];

    void _rotate90() {
        int temp[22][22];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                temp[i][j] = a[n-1-j][i];
            }
        }
        memcpy(a, temp, sizeof(temp));
    }

    void _mymove() {
        for(int i=0; i<n; i++) {
            int flag=0;
            for(int j=1; j<n-1; j++) {
                if(a[i][j] != 0) {
                    for(int k=j+1; k<n; k++) {
                        if(a[i][k] != 0) {
                            if(a[i][k] == a[i][j]) {
                                a[i][j] += a[i][k];
                                a[i][k] = 0;
                            }
                            continue;
                        }
                    }
                }    
            }
        }
    }
    int _getMax() {
        return 1;
    }

    void _printBoard() {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Board b;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> b.a[i][j];
        }
    }

    
}