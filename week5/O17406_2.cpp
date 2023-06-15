/*
https://www.acmicpc.net/problem/17406
*/
#include <iostream>
#include <vector>
using namespace std;

int n,m,k,r,c,s, int a[54][54];

// right down left up
const int dy[] = {0,1,0,-1};
const int dx[] = {1,0,-1,0}; 

struct rot {
    int r,c,s;
}


void rotateAll(int y, int x, int cnt) {
    for(int i=1; i<=cnt; i++) {
        sy = y - 1*i;
        sx = x - 1*i;
        ey = y + 1*i;
        ex = x + 1*i;
    }
}


int main() {
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i=0; i<k; i++) {
        cin >> r >> c >> s;

    }
}