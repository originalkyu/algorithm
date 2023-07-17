/*
https://www.acmicpc.net/problem/14003
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[1'000'004];
int cnt[1'000'004];
int trace[1'000'004];
int n, mxv;
int mxCntIdx, mxCnt;

int main() {

    /*
        ver 1
    */
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    fill(a,a+1000004,0);
    fill(cnt,cnt+1000004,0);
    fill(trace, trace+1000004, -1);
    mxCnt=0;
    for(int i=0; i<n; i++) {
        mxv=0;
        for(int j=0; j<i; j++) {
            if(a[j] < a[i] && mxv < cnt[j]) {
                mxv = cnt[j];
                trace[i] = j;
            }
        }
        cnt[i] = mxv+1;
        if(mxCnt < cnt[i]) {
            mxCntIdx = i;
            mxCnt = cnt[i];
        }
    }

    cout << mxCnt << "\n";
    int idx = mxCntIdx;
    while(idx != -1) {
        cout << idx << " ";
        idx = trace[idx];
    }
    cout << "\n";

}

/*
6
10 20 10 30 20 50
*/