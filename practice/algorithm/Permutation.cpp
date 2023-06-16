#include <iostream>
#include <vector>
#include <algorithm> // next_permutation(), prev_permutation()
#include <utility> // swap
using namespace std;

struct loc {
    int x,y,z;

    bool operator < (const loc &a) const {
        if(x==a.x && y==a.y) return z < a.z;
        if(y==a.y) return y < a.y;
        return x < a.x;
    }

    void print_loc() {
        cout << x << " " << y << " " << z << " ";
        cout << "\n";
    }
};


void printV(vector<int> &v) {
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

/*
pattern

for loop 1
2 <-> 2
1 2 3 4 *
1 2 4 3 *

2 <-> 3
1 3 2 4
1 3 4 2

2 <-> 4
1 4 2 3 *
1 4 3 2 *

for loop 2
2 1 3 4


*/
void makePermutation(vector<int> &v, int n, int end_depth, int depth) {
    if(end_depth == depth) {
        printV(v);
        return;
    }
    for(int i=depth; i<n; i++) {
        swap(v[i], v[depth]);
        makePermutation(v, n, end_depth, depth+1);
        swap(v[i], v[depth]);
    }
}

int main() {
    int cnt=0;
    int a[3] = {1,2,3};
    vector<int> v;


    // next_permutation() : 반드시 sort를 먼저 할 것!!!
    cout << "next_permutation()" << "\n";
    for(int i=0; i<3; i++) v.push_back(a[i]);
    do {
        printV(v);
    } while(next_permutation(v.begin(), v.end()));

    cout << "prev_permutation()" << "\n";
    v.clear();
    for(int i=2; i<=0; i--) v.push_back(a[i]);
    // do {
    //     printV(v);
    // } while(prev_permutation(v.begin(), v.end()));


    /*
        next_permutation and struct
    */
    vector<loc> loc_vec1 = {{1,2,6},{1,2,3},{2,3,4},{3,4,5}};
    cout << "loc_vec------" << "\n";
    cnt=0;
    do {
        cout << ++cnt << "\n";
        for(auto el : loc_vec1) el.print_loc();
    } while(next_permutation(loc_vec1.begin(), loc_vec1.end()));

    // after sort
    vector<loc> loc_vec2 = {{1,2,6},{1,2,3},{2,3,4},{3,4,5}};
    sort(loc_vec2.begin(), loc_vec2.end());
    cout << "loc_vec------" << "\n";
    cnt=0;
    do {
        cout << ++cnt << "\n";
        for(auto el : loc_vec2) el.print_loc();
    } while(next_permutation(loc_vec2.begin(), loc_vec2.end()));

    /*
        next_permutation and char vector
    */
    vector<char> ch_vec1 = {'*','+'};
    vector<char> ch_vec2 = {'+', '*'};
    cnt=0;
    do {
        cout << ++cnt << "\n";
        for(auto el : ch_vec1) cout << el << " ";
        cout << "\n";
    } while(next_permutation(ch_vec1.begin(), ch_vec1.end()));

    cnt=0;
    do {
        cout << ++cnt << "\n";
        for(auto el : ch_vec2) cout << el << " ";
        cout << "\n";
    } while(next_permutation(ch_vec2.begin(), ch_vec2.end()));
    // recursive
    cout << "recursive: " << "\n";
    v.clear();
    for(int i=0; i<4; i++) v.push_back(a[i]);
    // makePermutation(v,4,4,0);
}