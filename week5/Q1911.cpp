/*
https://www.acmicpc.net/problem/1911
*/

/*
1 <= N <= 10,000 개의 물웅덩이
l : 널빤지 길이
*/
#include <iostream>
#include <vector>
#include <algorithm> // sort
using namespace std;

int n, l, x, xlen;
vector<pair<int, int>> v;
vector<pair<int, int>> ls;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    return a.first < b.first;
}
int main() {
    cin >> n >> l;
    for(int i=0; i<n; i++) {
        cin >> x >> xlen;
        v.push_back({x,xlen});
    }
    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<n; i++) {
        
    }
}

/*
10억
*/