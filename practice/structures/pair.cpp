#include <iostream>
#include <utility> // pair
#include <vector>
using namespace std;

int main() {
    pair<int, char> p;

    // 방법1
    p.first = 1;
    p.second = 'a';

    // 방법2
    p = make_pair(1,'a');

    cout << p.first << p.second << "\n";

    // 방법1
    int x1 = p.first;
    char y1 = p.second;

    // 방법2
    int x2; char y2;
    tie(x2, y2) = p;
    tie(x2, ignore) = p;


    vector<pair<int,int>> vp;
    vp.push_back({1,2});
}