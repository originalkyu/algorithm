#include <iostream>
#include <vector>
using namespace std;



// 오른쪽으로 90도 회전
void r_rotate90(vector<vector<int>> &m) {
    int n = m.size();
    vector<vector<int>> temp(n, vector<int>(n,0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            temp[i][j] = m[n-j-1][i];
        }
    }
    m = temp;
    return;
}

int main() {

    vector<vector<int>> vv = vector<vector<int>>(3, vector<int>(3,0));
    vv[0][2] = 3; vv[1][2] = 3; vv[2][2] = 3;
    for(auto v : vv) {
        for(auto el : v) {
            cout << el << " ";
        }
        cout << "\n";
    }

    r_rotate90(vv);
    for(auto v : vv) {
        for(auto el : v) {
            cout << el << " ";
        }
        cout << "\n";
    }

    r_rotate90(vv);
    for(auto v : vv) {
        for(auto el : v) {
            cout << el << " ";
        }
        cout << "\n";
    }

    r_rotate90(vv);
    for(auto v : vv) {
        for(auto el : v) {
            cout << el << " ";
        }
        cout << "\n";
    }
    
}