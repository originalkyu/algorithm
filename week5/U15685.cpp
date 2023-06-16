/*
https://www.acmicpc.net/problem/15685
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, x, y, d, g;
int a[104][104];
int cnt=0;
vector<int> v;

const int dy[] = {0,-1,0,1}; // right up left down
const int dx[] = {1,0,-1,0};


void drawDD(int x, int y, int d, int g, int now_depth) {
    if(g==now_depth) {
        int ny = y+dy[v[0]]; int nx = x+dx[v[0]];
        int nny,nnx;
        a[ny][nx]=1;
        for(int i=1; i<v.size(); i++) {
            nny = ny+dy[v[i]]; nnx = nx+dx[v[i]];
            a[nny][nnx] = 1;
            ny = nny; nx = nnx;
        }
        return;
    }
    for(int i=v.size()-1; i>=0; i--) v.push_back((v[i]+1)%4);
    drawDD(x,y,d,g,now_depth+1);
}

void checksquare() {
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            if(a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) cnt++;
        }
    }
}

int main() {
    memset(a, 0, sizeof(a));
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x >> y >> d >> g;
        a[y][x] = 1;
        v.clear();
        v.push_back(d);
        drawDD(x,y,d,g,0);
    }

    checksquare();
    cout << cnt << "\n";
}