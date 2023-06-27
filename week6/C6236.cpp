/*
https://www.acmicpc.net/problem/6236
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n,m, bg, ed, ret, k, remain, total, mx=0;
int nday[100001];

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> nday[i];
        mx = max(nday[i], mx);
    }

    bg = mx;
    ed = mx*n;
    ret = mx*n;
    while(bg < ed) {
        k = (bg+ed)/2;
        total = 0;
        remain=0;
        for(int i=0; i<n; i++) {
            if(remain < nday[i]) {
                total += 1;
                remain = k - nday[i];
            }
            else {
                remain -= nday[i]; 
            }
        }
        if(total <= m) {
            ret = min(ret, k);
            ed = k;
        }
        else if(total > m) bg = k+1;
        // else if(total < m) ed = k;

        // cout << bg << " " << ed << " " << k << " " <<  total <<  "\n";
    }
    cout << ret << "\n";
}