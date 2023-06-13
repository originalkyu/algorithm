#include <iostream>
#include <algorithm> // sort
#include <vector>
#include <stack>
using namespace std;

struct Point {
    int y,x;
    Point(int _y, int _x) : y(_y), x(_x) {}
    Point() {y=-1; x=-1;}

    bool operator < (const Point &a) const {
        // return x > a.x; // 내림차순
        return x < a.x; // 오름차순
    }
    // operator > 를 오버라이딩하면 error가 난다.
};


struct coordinate {
    int y,x;
    coordinate(int _y, int _x) : y(_y), x(_x) {}
    coordinate() {y=-1; x=-1;}
};

typedef Point pt;
typedef coordinate cd

bool cmp(const cd &a, const cd &b) {
    return a.x < b.x;
}

int main() {

    /*
        bool operator overriding
    */
    vector<pt> v;
    for(int i=0; i<10; i++) {
        pt a = {i,10-i};
        pt b = {i,10-i};
        v.push_back(a);
        v.push_back(b);
    }
    sort(v.begin(), v.end());
    for(auto el : v) cout << el.x << " ";

    /*
        custom compare
    */
    stack<cd> h;
    for(int i=0; i<10; i++) {
        cd a = {i, 10-i};
        h.push(a);
    }
}