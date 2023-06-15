#include <iostream>
#include <vector>
#include <cstring> // memcpy
#include <algorithm>
using namespace std;

#deinf

const int INF = 987654321;
const int dy[] = {0,1,0,-1}; // right, down, left, up
const int dx[] = {1,0,-1,0};

int n,m,k,a[54][54], ret=INF, r,c,s;
int b[54][54];
struct A{
    int y,x,cnt;

    // bool operator < (const A &a) const {
    //     return y < a.y;
    // }
};
vector<A> v1, v2;
vector<int> v_idx;
vector<pair<int, int>> vv;


void go(int y, int x, int first) {
    if(!fi)
}

void rotateAll(int y, int x, int cnt) {
    for(int i=1; i<=cnt; i++) {
        sy = y - 1*i;
        sx = x - 1*i;
        ey = y + 1*i;
        ex = x + 1*i;
        vv.clear();
        dir = 0;
        memset(visited, 0, sizeof(visited));
        visited[sy][sx]=1;
        vv.push_back({sy, sx});
        go(sy, sx, 1);
        vector<int> vvv;
        for(pair<int, int> c : vv) vvv.push_back(b[c.f][c.s]);
        rotate(vvv.begin(), vvv.begin() + vvv.size() - 1, vvv.end());
        for(int i=0; i<vv.size(); i++) b[vv[i].f][vv[i].s] = vvv[i];
    }
}

int solve() {
    for(int i : v_idx) rotateAll(v[i].y, v[i].x v[i].cnt);
    int _ret = INF;
    for(int i=0; i<n; i++) {
        int cnt=0;
        for(int j=0; j<m; j++) cnt += b[i][j];
        _ret = min(_ret, cnt);
    }
    return _ret;
}


int main() {
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i=0; i<k; i++) {
        cin >>r >> c >> s;
        v.push_back({r-1,c-1,s});
        v_idx.push_back(i);
    }
    do {
        memcpy(b, a, sizeof(b));
        ret = min(ret, solve());
    } while(next_permutation(v_idx.begin(), v_idx.end()));
    cout << ret << "\n";
    return 0;
}