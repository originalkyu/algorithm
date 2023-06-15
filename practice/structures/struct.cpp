/*
참고 : https://www.geeksforgeeks.org/structures-in-cpp/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct loc {
    int y,x;
};

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
    // list initialization -> 이용할 방법
    loc l {2,3};

    // copy-list initialization
    Point po = {1,2}; 

    // vector and struct
    vector<Point> v1;
    for(int i=10; i>=1; i--) {
        Point a = {i,i};
        v1.push_back(a);
    }

    vector<Point> v2;
    for(int i=19; i>=1; i--) {
        v2.push_back({i,i});
    }

    vector<Point> v3 = { Point{1,10}, Point{2,9}, Point{3,8}, Point{4,7} };
    vector<Point> v4 = { {1,10}, {2,9}, {3,8}, {4,7} };

    
    sort(v1.begin(), v1.end());
    for(auto it : v2) cout << it.y << " : " << it.x << "\n";
    // cmp 로 sort
    sort(v4.begin(), v4.end(), cmp);
    for(auto it : v4) cout << it.y << " : " << it.x << "\n";
}
