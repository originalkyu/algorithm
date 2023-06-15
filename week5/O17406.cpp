/*
https://www.acmicpc.net/problem/17406
*/
#include <iostream>
#include <cstring> // memcpy()
#include <algorithm> // max()
#include <vector>
using namespace std;

struct rot {
    int r,c,s;
};

int in[54][54];
int in_rot[54][54];
int n,m,k;
int _r, _s, _c;
vector<int> v_idx;
vector<rot> v;
int mn = 987654321;


void rotate1b(int r, int c, int s) {
    if(s==0) return;
    // down right up  left
    int temp = in_rot[r-s][c-s];
    for(int i=r-s; i< r+s; i++) {// (r+s-1)-(r-s)+1=2s
        in_rot[i][c-s] = in_rot[i+1][c-s];
    }
    for(int i=c-s; i<c+s; i++) {
        in_rot[r+s][i] = in_rot[r+s][i+1];
    }
    for(int i=r+s; i>r-s; i--) {
        in_rot[i][c+s] = in_rot[i-1][c+s];
    }
    for(int i=c+s; i>c-s; i--) {
        in_rot[r-s][i] = in_rot[r-s][i-1];
    }
    in_rot[r-s][c-s+1]=temp;
    return;
}

void get_mn() {
    for(int i=0; i<n; i++) {
        int sum=0;
        for(int j=0; j<m; j++) {
            sum+=in_rot[i][j];
        }
        mn = min(mn, sum);
    }
}

int main() {
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> in[i][j];
        }
    }
    for(int i=0; i<k; i++) {
        cin >> _r >> _c >> _s;
        v.push_back({_r-1, _c-1, _s});
        v_idx.push_back(i);
    }

    do {
        memcpy(in_rot, in, sizeof(in_rot));
        for(int idx : v_idx) {
            int cnt = v[idx].s;
            while(cnt) rotate1b(v[idx].r, v[idx].c, cnt--);
        }
        get_mn();
    } while(next_permutation(v_idx.begin(), v_idx.end()));



    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << mn << "\n";
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

5 6 1
1 2 3 2 5 6
3 8 7 2 1 3
8 2 3 1 4 5
3 4 5 1 1 1
9 3 2 1 4 3
4 2 1
*/