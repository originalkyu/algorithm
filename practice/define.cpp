#include <iostream>
#include <vector>
#include <utility> // pair
using namespace std;


// #define [new name] [orignal]
#define f first
#define s second

int main() {
    int a[4][4];

    int val = 0;
    vector<pair<int, int>> v;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++)
            a[i][j] = ++val;
        v.push_back({i,i});
    }

    for(auto el : v) {
        // cout << el.first << " " << el.second << "\n"; // #define으로 해결
        cout << el.f << " " << el.s << "\n";
    }


}