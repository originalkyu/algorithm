/*
https://www.acmicpc.net/problem/17406
*/
#include <iostream>
#include <cstring> // memcpy()
#include <algorithm> // max()
using namespace std;

int a[54][54];
int n,m,k;
int _r, _s, _c;



void rotate1b(int r, int c, int s) {
    if(s==0) return;
    // down right up  left
    int temp = a[r-s][c-s];
    for(int i=r-s; i< r+s; i++) {// (r+s-1)-(r-s)+1=2s
        a[i][c-s] = a[i+1][c-s];
    }
    for(int i=c-s; i<c+s; i++) {
        a[r+s][i] = a[r+s][i+1];
    }
    for(int i=r+s; i>r-s; i--) {
        a[i][c+s] = a[i-1][c+s];
    }
    for(int i=c+s; i>c-s; i--) {
        a[r-s][i] = a[r-s][i-1];
    }
    a[r-s][c-s+1]=temp;
    return;
}

int get_Max() {
    int mn=99999999;
    for(int i=0; i<n; i++) {
        int sum=0;
        for(int j=0; j<m; j++) {
            sum+=a[i][j];
        }
        mn = min(mn, sum);
    }
    return mn;
}

int main() {
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i=0; i<k; i++) {
        cin >> _r >> _c >> _s;
        while(_s > 0 ) {
            rotate1b(_r-1, _c-1, _s);
            _s--;
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << get_Max()<< "\n";
}

/* inputs
5 6 1
1 2 3 2 5 6
3 8 7 2 1 3
8 2 3 1 4 5
3 4 5 1 1 1
9 3 2 1 4 3
3 4 2


5 6 2
1 2 3 2 5 6
3 8 7 2 1 3
8 2 3 1 4 5
3 4 5 1 1 1
9 3 2 1 4 3
3 4 2
4 2 1
*/