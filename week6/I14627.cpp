/*
https://www.acmicpc.net/problem/14627
*/
/*
- 파를 여러 개 구입
- 같은 양의 파 - 최대한 많이
- 남은 파를 라면에 넣기
- 파는 정수 크기로만 자를 수 있다.
입력
- 파의 수 s
- 파닭의 수 c
s <= c


*/

#include <iostream>
#include <algorithm>
using namespace std;

int s, c, mxl;
int sarr[1'000'000];

long ret;


int main() {
    cin >> s >> c;

    mxl=0;
    for(int i=0; i<s; i++) {
        cin >> sarr[i];
        mxl = max(mxl, sarr[i]);
    }

    // 파닭의 넣은 파의 길이
    int bg=1, ed=mxl;
    int cnt=0;
    ret = 0;
    long long mid;
    while(bg<=ed) {
        mid = (bg+ed)/2;
        cnt=0;
        for(int i=0; i<s; i++) cnt += sarr[i]/mid;
        if(cnt==c) {
            if (ret < mid) ret = mid;
            bg = mid+1;
        }
        else if(cnt>c) bg = mid+1;
        else if(cnt<c) ed = mid-1;
    }

    // 남은 파의 길이
    int leftover=0;
    for(int i=0; i<s; i++) {
        leftover += sarr[i]%ret;
    }
    cout << leftover << "\n";
}

/*

3 5
440
350
230


*/