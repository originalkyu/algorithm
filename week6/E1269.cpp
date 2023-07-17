/*
https://www.acmicpc.net/problem/1269
*/
/*
문제 읽기
- 공집합x
- 대칭 차집합의 원소의 개수
    - 각각 2 x 1e5 개 이하
- 값은 최대 1e8
*/

#include <iostream>
#include <algorithm>
using namespace std;

// 입력
int na, nb;
int as[200002], bs[200002];

// 
int cnt;

bool findbnum(int bnum) {
    int bg=0;
    int ed=na-1;
    int mid;
    while(bg <= ed) { 
        mid = (bg+ed)/2;
        //cout << " " << bg << " " << ed << " " << bnum << " " << as[mid] << "\n";
        if(bnum == as[mid]) return true;
        else if(bnum > as[mid]) {
            bg=mid+1;
        }
        else if (bnum < as[mid]) {
            ed=mid-1;
        }
    }
    return false;
}

int main() {
    cin >> na >> nb;
    for(int i=0; i<na; i++) {
        cin >> as[i];
    }
    for(int i=0; i<nb; i++) cin >> bs[i];

    sort(as, as+na);
    //sort(bs, bs+nb);
    cnt = 0;
    for(int i=0; i<nb; i++) {
        if(findbnum(bs[i])) cnt++;
    }
    cout << na+nb-2*cnt << "\n";

}

/*
문제 분석:
*/