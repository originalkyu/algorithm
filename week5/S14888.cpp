/*
https://www.acmicpc.net/problem/14888
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,cnt, mn=1987654321, mx=-1987654321;
int arr[12];
char opers[] = {'+','-','*','/'};
vector<char> v;
int cal(int n1, int n2, char oper) {
    switch(oper) {
        case '+':
            return n1+n2;
        case '-':
            return n1-n2;
        case '*':
            return n1*n2;
        case '/':
            return n1/n2;
        default:
            return 0;
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<4; i++) {
        cin >> cnt;
        for(int j=0; j<cnt; j++) v.push_back(opers[i]);
    }

    sort(v.begin(), v.end());
    do {
        int ret = arr[0];
        for(unsigned int i=0; i<v.size(); i++) {
            ret = cal(ret,arr[i+1], v[i]);
        }
        mn = min(mn, ret);
        mx = max(mx, ret);
    } while(next_permutation(v.begin(), v.end()));

    cout << mx << "\n";
    cout << mn << "\n";
}