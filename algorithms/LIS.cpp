/*
핵심 아이디어: 이전의 최대값에 쌓아가는 방식
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// ver 1
int n, a[1001], cnt[1001], ret;

// ver 2
int idx;
int prev_list[1001];
vector<int> real;

void go(int idx) {
    if(idx==-1) return;
    real.push_back(a[idx]);

    go(prev_list[idx]);
    return;
}

// ver3
int lis[1001], len, num;

int main() {

    /*
        ver 1
        O(n^2)
    */ 
    // cin >> n;
    // for(int i=0; i<n; i++) cin >> a[i];

    // // mxV는 i번째보다 값이 작 것의 개수+1
    // // cnt[] 는 mxV 값
    // for(int i=0; i<n; i++) {
    //     int maxValue = 0; 
    //     for(int j=0; j<i; j++) {
    //         if(a[j] < a[i] && maxValue < cnt[j]) maxValue = cnt[j]; 
    //         // 현재(=i) 가 이전 것(=j)보다 크고 
    //         // 현재의 mxV가 이전 것의 mxV보다 작으면 이전 것의 mxV를 취한다. 
    //     }
    //     cnt[i] = maxValue+1; // 
    //     ret = max(ret, cnt[i]); 
    // }
    // for(int i=0; i<n; i++) {
    //     cout << cnt[i] << " ";
    // }
    // cout << ret << "\n";


    /*
        ver 2
        이전의 위치를 저장한다.
    */
    // cin >> n;
    // for(int i=0; i<n; i++) cin >> a[i];

    // fill(cnt, cnt+1001, 1);
    // fill(prev_list, prev_list+1001, -1);
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<i; j++) {
    //         if(a[j] < a[i] && cnt[i] < cnt[j]+1) {
    //             cnt[i] = cnt[j]+1;
    //             prev_list[i] = j;
    //             if(ret < cnt[i]) {
    //                 ret = cnt[i];
    //                 idx = i;
    //             }
    //         }
    //     }
    // }
    // cout << ret << "\n";
        // recursive
    // go(idx);
        // for loop
    // int i = idx;
    // for(; prev_list[i] != -1; i=prev_list[i]) real.push_back(a[i]);
    // real.push_back(a[i]);
    // for(int i=real.size()-1; i>=0; i--) {
    //     cout << real[i] << " ";
    // }


    /* 
        ver 3
        lower_bound를 이용한다.
        O(nlogn)
    */
    cin >> n;

    fill(lis,lis+1001,0);
    len = 0;
    for(int i=0; i<n; i++) {
        cin >> num;
        auto lowerPos = lower_bound(lis, lis+len, num); // O(log n), num 이상의 값의 첫 위치
        // *lowerPos 는 최초의 num 이상의 값의 위치: 없다면 end() 위치의 값 반환
        if(*lowerPos == 0) len++; 
        cout << *lowerPos << "\n";
        *lowerPos = num; // *lowerPos의 값을 바꿈
            // 주의 : 이터레이터는 포인터가 아님. *가 오버로딩 되어 있어 포인터처럼 쓸 수 있는 것.
        for(int j=0; j<n; j++) {
            cout << lis[j] << " ";
        }
        cout << "\n";
    }
    cout << len << "\n";
}
/*
6
10 20 10 30 20 50

{10}
{10,20}

*/
