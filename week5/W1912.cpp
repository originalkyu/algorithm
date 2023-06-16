/*
https://www.acmicpc.net/problem/1912


1. 입력받은 수 num이 양수라면 
    이전 temp가 있다면
        sum += temp
        temp_old = temp
        temp = num
    이전 temp가 없다면
        temp = num
2. 입력받은 수 num이 양수가 아니라면 
    case 1 : temp+num이 0보다 작으면
        sum += temp
        ret = max(sum, ret)
        sum = 0
        temp 지우기
    case 2 : temp+num이 0보다 작지 않으면
        temp += num

조건부 누적합?
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int INF=1987654321;
int n;
int num, sum=0, ret=-INF, temp=-INF, temp_old=-INF;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> num;

        if(num > 0) { // 양수일 때
            if(temp != -INF) { // 이전 양수가 있을 때
                if(temp_old != -INF) sum += temp_old;
                temp_old=temp;
                temp = num;
            }
            else if(temp == -INF) {
                temp_old=num;
                temp = num;
            }
        } // num(==temp)이 현재 sum에 반영이 안됨
        else { // 음수일 때
            if(temp != -INF) { // 이전 양수가 있을 때
                if(temp+num <0) {
                    sum += temp;
                    ret = max(sum, ret);
                    sum = 0;
                    temp = -INF;
                }
                else { 
                    temp += num;
                }
            }
            else {
                ret = max(ret, num);
            }
            // else (temp == -INF) { // 이전 양수가 없을 때
            //     ret = max(ret, num);
            // }
        }
    }
    if(temp >=0) {
        sum += max(temp,temp_old);
        ret = max(ret, sum);
    }

    cout << ret << "\n";
}

/*
10
10 -4 3 1 5 6 -35 12 21 -1

10
2 1 -4 3 4 -4 6 5 -5 1
*/