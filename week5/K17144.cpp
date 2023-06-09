/*
https://www.acmicpc.net/problem/17144
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int a[52][52], r, c, t, flag=0;
int dy1[] = {0, -1, 0, 1}; // right up left down
int dx1[] = {1, 0, -1, 0};
int dy2[] = {0,-1,0,1}; // right down left up
int dx2[] = {1,0,-1,0};

queue<pair<int,int>> q1, q2;

void spread() {

}

void wind() {

}


int main() {
    cin >> r >> c >> t;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> a[i][j];
            if(a[i][j] == -1) flag++;
            if(flag < 2) {
                q1.push({i,j});  
            }
            else {
                q2.push({i,j});
            }
        }
    }

    while(t--) {
        spread();
        wind(dy1, dx1, q1);
        wind(dy2, dx2, q2);
    }
}
