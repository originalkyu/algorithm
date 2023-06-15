/*
https://www.acmicpc.net/problem/12100
*/
#include <iostream>
#include <cstring> // memcpy(), memset()
#include <algorithm> // max()
using namespace std;


int n;
int mx;
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

    void _mymove() { // 왼쪽으로 밀기
        int temp[22][22];
        memset(temp, 0, sizeof(temp));

        for(int i=0; i<n; i++) {
            int cp_loc=0;
            int flag=1;
            temp[i][0] = a[i][0];
            for(int j=1; j<n; j++) {
                if(a[i][j]==0) continue;
                //////
                if(temp[i][cp_loc] == 0) {
                    temp[i][cp_loc] = a[i][j];
                    flag = 1;
                } 
                else if(flag && temp[i][cp_loc] == a[i][j]) {
                    temp[i][cp_loc++] = 2*a[i][j];
                    flag = 0;
                }
                else {
                    temp[i][++cp_loc] = a[i][j];
                    flag = 1;
                };
            }
        }
        memcpy(a, temp, sizeof(temp));
    }
    // void _mymove() { // 왼쪽으로 밀기
    //     int temp[22][22];
    //     memset(temp, 0, sizeof(temp));

    //     for(int i=0; i<n; i++) {
    //         int cp_loc=-1;
    //         int flag=0;
    //         for(int j=0; j<n; j++) {
    //             if(a[i][j] ==0) continue;
    //             //////
    //             if(flag && temp[i][cp_loc] == a[i][j]) {
    //                 temp[i][cp_loc] = 2*a[i][j];
    //                 flag = 0;
    //             }
    //             else {
    //                 temp[i][++cp_loc] = a[i][j];
    //                 flag = 1;
    //             }
    //         }
    //     }
    //     memcpy(a, temp, sizeof(temp));
    // }


    void _getMax() {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                mx = max(mx, a[i][j]);
            }
        }
        
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

void go(int cnt,Board b) {
    if(cnt==0) {
        b._getMax();
        return;
    }
    for(int i=0; i<4; i++) {
        Board c = b;
        c._mymove();
        go(cnt-1, c);
        b._rotate90();
    }
    return;
}

int main() {
    Board b;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> b.a[i][j];
        }
    }
    mx = 0;
    go(5,b);
    cout << mx << "\n";
    
}