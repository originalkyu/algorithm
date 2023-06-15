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

#define f first
#define s second
typedef unsigned int uint;
int n, l, bg, ed;
vector<pair<int, int>> v;
vector<pair<int, int>> ls;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    return a.f < b.f;
}


int main() {
    cin >> n >> l;
    for(int i=0; i<n; i++) {
        cin >> bg >> ed;
        v.push_back({bg, ed});
    }
    sort(v.begin(), v.end(), cmp);

    int cnt=0;
    pair<int, int> temp;
    int len = v[0].s - v[0].f;
    int add = len / l;
    if(len % l) add++;
    cnt+=add;

    temp = v[0];
    temp.s = temp.f + add*l;
    for(uint i=1; i<v.size(); i++) {
        if(v[i].s <= temp.s) continue;
        else if(v[i].f < temp.s && v[i].s > temp.s) {
            len = (v[i].s - temp.s);
            add = len / l;
            if(len % l) add++;
            cnt += add;
            temp.second += add * l;
        }
        else {
            len = (v[i].s - v[i].f);
             add = len / l;
             if(len%l) add++;
             cnt += add;
             temp=v[i];
             temp.s = v[i].f + add*l;
        }
    }
    // for(auto el : ls) {
    //     cout << el.first << " " << el.second << "\n";
    // }
    cout << cnt << "\n";
}

/*
10억
*/