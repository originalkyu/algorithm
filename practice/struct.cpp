#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// struct
struct Point {
    int y,x;
    Point(int _y, int _x) : y(_y), x(_x) {}
    Point() {y=-1; x=-1;}

    bool operator < (const Point & a) const {
        return x > a.x;
    }
};
// 마지막에 반드시 ; 을 붙여준다.

struct percent {
    int x, y;
    double w, d, l;
} per[6];

bool cmp(const Point & a, const Point & b) {
    return a.x < b.x;
}

int main() {
    // struct
    vector<Point> v;
    for(int i=10; i>=1; i--) {
        Point a = {i,i};
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    for(auto it : v) cout << it.y << " : " << it.x << "\n";
    // cmp 로 sort
    sort(v.begin(), v.end(), cmp);
    for(auto it : v) cout << it.y << " : " << it.x << "\n";
}
