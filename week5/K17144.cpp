/*
https://www.acmicpc.net/problem/17144
*/
#include <iostream>
#include <utility> // pair
#include <queue>
#include <algorithm> // fill
#include <tuple> // tie()
using namespace std;

int a[52][52], r, c, t, temp[52][52];
int lc;
int dy[] = {1,0,-1,0}; // down left up right
int dx[] = {0,-1,0,1};

queue<pair<int,int>> q1, q2;

void spread() {
    fill(&temp[0][0], &temp[0][0]+52*52, 0);
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(a[i][j] != -1 && a[i][j] != 0) {
                int l=0;
                for(int k=0; k<4; k++) {
                    int ny = i+dy[k]; int nx = j+dx[k];
                    if(a[ny][nx]==-1) continue;
                    if(ny <0 || ny >= r || nx <0 || nx >=c) continue;
                    temp[ny][nx] += a[i][j]/5; 
                    l++;
                };
                temp[i][j] += (a[i][j] - l*(a[i][j]/5));
            }
        }
    }
    for(int i=0; i<r; i++) {
        for(int j=0;j <c; j++) {
            if(a[i][j] != -1)
                a[i][j] = temp[i][j];
        }
    }
}

void set_q1q2() {
    // q1의 꼭지점
    //(0,0)    (0,c-1)
    //(lc-1,0) (lc-1, c-1)
    for(int i=lc-2; i>0; i--) q1.push({i,0}); // lc-2 ~ 0
    for(int j=0; j<c-1; j++) q1.push({0,j});
    for(int i=0; i<lc-1; i++) q1.push({i, c-1});
    for(int j=c-1; j>0; j--) q1.push({lc-1,j});
    // q2의 꼭지점
    //(lc,0)  (lc,c-1)
    //(r-1,0) (r-1,c-1)
    for(int i=lc+1; i<r-1; i++) q2.push({i,0});
    for(int j=0; j<c-1; j++) q2.push({r-1,j});
    for(int i=r-1; i>lc; i--) q2.push({i,c-1});
    for(int j=c-1; j>0; j--) q2.push({lc,j});
}

void wind(queue<pair<int,int>> &q) {
    int ty,tx;
    while(q.size() != 1) {
        tie(ty, tx) = q.front(); q.pop();
        a[ty][tx] = a[q.front().first][q.front().second];
    }
    a[q.front().first][q.front().second]=0; q.pop();
}


int main() {
    cin >> r >> c >> t;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> a[i][j];
            if(a[i][j] == -1) lc = i;
        }
    }

    while(t--) {
        spread();
        set_q1q2();
        wind(q1);
        wind(q2);
    }

    // cout << "---------\n";
    // for(int i=0; i<r; i++) {
    //     for(int j=0; j<c; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    int sum=0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            sum+=a[i][j];
        }
    }
    cout << sum+2 << "\n";
}
