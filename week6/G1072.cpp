/*
https://www.acmicpc.net/problem/1072
*/
/*
문제 읽기
- 게임 횟수: x
- 이긴 게임: y
- 형택 승률 : z = 정수%, 소수점 버림

x <= 1e9
0 <= y <= x

*/
#include <iostream>
#include <algorithm>
using namespace std;

// 입력
int x, y;

// 
const int INF=1e9;
int bg, ed;
double init=0;
double newz;
int flag=0; // 0 : z 변하지 않음, 1 : z 변함
int mid;
int ret;

int main() {
    cin >> x >> y;

    init = (100*(double(y) / double(x)));
    bg = 1;
    ed = INF;
    while(bg <= ed) {
        mid = (bg+ed)/2;
        newz=(100* (double(y+mid) / double(x+mid)));
        if(newz <= init) bg=mid+1;
        else if(newz > init && (int)newz == (int) init) {
            bg = mid+1;
        }
        else if(newz > init && (int)newz > (int) init) {
            flag=1;
            ed = mid-1;
            ret = mid;
            cout << newz << " " << init << " " << (newz > init) << "\n";
            cout << (int)newz << " " << (int)init << " " << ((int)newz > (int)init) << "\n";
            cout << mid << "\n";
        }
    }
    if(flag) cout << ret << "\n";
    else cout << -1 << "\n";
}