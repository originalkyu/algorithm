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
typedef unsigned int uint;
int n, l, bg, ed;
vector<pair<int, int>> v;
vector<pair<int, int>> ls;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    return a.first < b.first;
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
    int add = (v[0].second-v[0].first) / l;
    if((v[0].second-v[0].first)%l) add += 1;
    cnt += add;
    temp = v[0];
    temp.second = v[0].first + add*l;
    for(uint i=1; i<v.size(); i++) {
        if(v[i].second <= temp.second) continue;
        else if(v[i].first < temp.second && v[i].second > temp.second) {
            add = (v[i].second - temp.second) / l;
            if((v[i].second-v[i].first)%l) add += 1;;
            cnt += add;
            temp.second += add * l;
        }
        else {
             int add = (v[i].second-v[i].first) / l;
             if((v[i].second-v[i].first)%l) add += 1;
             cnt += add;
             temp=v[i];
             temp.second = v[i].first + add*l;
        }
    }
    // for(auto el : ls) {
    //     cout << el.first << " " << el.second << "\n";
    // }
    cout << cnt;
}

/*
10억
*/