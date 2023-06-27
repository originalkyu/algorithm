/*
https://www.acmicpc.net/problem/2792
*/
/*
10^9 = 1,000,000,000 => int
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, mx, num, ret, bg, ed, cnt;
int ms[300004];

int main() {
    cin >> n >> m;

    mx = 0;
    for(int i=0; i<m; i++) {
        cin >> ms[i];
        mx = max(ms[i],mx);
    }

    bg=1;
    ed=mx;
    ret = mx;
    while(bg < ed) {
        cnt = (bg+ed)/2;
        num = 0;
        for(int i=0; i<m; i++) {
            num += ms[i] / cnt;
            if(ms[i] % cnt) num++;
        }

        if(num > n) bg = cnt+1;
        else if(num <= n) {
            ed = cnt;
            ret = min(ret, cnt);
        }
    }
    cout << ret << "\n";
    
}