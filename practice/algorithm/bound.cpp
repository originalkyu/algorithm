/*
lower_bound와 upper_bound
lower_bound: 배열의 앞에서부터 "찾는 값 이상의 값"의 첫 위치
upper_bound: 배열의 뒤에서부터 "찾는 값 이상의 값"의 다음 위치
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void coutResult(int x,int c, int f, int t, int f2, int t2) {
    cout << x << " cnt : " << c << ", begin : " << f << "  end : " << t << "\n";
    cout << "lower bound val: " << f2 << "  upper bound val: " << t2 << "\n";
    // cout << "hello"; 
}

int main() {
    int a[5] = {1,2,2,2,3};
    // int b[8] = {1,2,3,4,5,6,7,8};
    // vector<int> v = {1,2,2,2,3};
    vector<int> v;


    /*
        vector and bound
    */
    v.insert(v.end(), a, a + ((sizeof(a)) /sizeof(int)));
    int x = 2;
    int c = (int)(upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(),x));
    cout << c << "\n";
    int f = (int)(lower_bound(v.begin(), v.end(), x) - v.begin());
    int t = (int)(upper_bound(v.begin(), v.end(), x) - v.begin());

    int f2 = *lower_bound(v.begin(), v.end(), x);
    int t2 = *upper_bound(v.begin(), v.end(), x);

    coutResult(x,c,f,t,f2,t2);
    /*
        array and bound
    */
    c = (int)(upper_bound(a, a+5, x) - lower_bound(a, a+5, x));
    f = (int)(lower_bound(a, a+5, x) - a);
    t = (int)(upper_bound(a, a+5, x) - a);

    f2 = *lower_bound(a, a+5, x);
    t2 = *upper_bound(a, a+5, x);
    coutResult(x,c,f,t,f2,t2);
}