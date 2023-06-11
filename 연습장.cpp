#include <iostream>
#include <algorithm>
#include <vector>
using namespace;

struct Point {
    int y,x;
    Point(int _y, int _x) : y(_y), x(_x) {}
    Point() {y=-1; x=-1;}

    bool operator < (const Point & a) {
        return x > a.x;
    }

    /*
    bool operator > (const Point & a) {
        return x > a.x;
    }
    */
}

bool cmp(const Point & a, const Point & b) {
    return a.x < b.x;
    // return a.x > b.x;
}

int main() {
    // struct
    vector<Point> v;
    for(int i)
}