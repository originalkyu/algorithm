#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point {
    int y,x;
    Point(int _y, int _x) : y(_y), x(_x) {}
    Point() {y=-1; x=-1;}

    bool operator < (const Point &a) const {
        return x > a.x;
    }
};

typedef struct Point pt;

int main() {
    // Point a(1,2);
    // cout << a.y << " " << a.x;
}