#include <iostream>
#include <vector>
#include <algorithm> // next_permutation(), prev_permutation()
#include <utility> // swap

using namespace std;

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
    int a[3] = {1,2,3};
    vector<int> v;


    // next_permutation()
    cout << "next_permutation()" << "\n";
    for(int i=0; i<3; i++) v.push_back(a[i]);
    do {
        printV(v);
    } while(next_permutation(v.begin(), v.end()));

    cout << "prev_permutation()" << "\n";
    v.clear();
    for(int i=2; i<=0; i--) v.push_back(a[i]);
    do {
        printV(v);
    } while(prev_permutation(v.begin(), v.end()));
    // recursive
    cout << "recursive: " << "\n";
    v.clear();
    for(int i=0; i<4; i++) v.push_back(a[i]);
    makePermutation(v,4,4,0);
}