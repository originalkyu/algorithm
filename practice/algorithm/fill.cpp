#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int a[10];
    vector<int> v = vector<int>(10,3);
    for(int i=0; i<10; i++)  a[i]=i;

    fill(a, a+5, 1);
    for(int i=0; i<10; i++) cout << a[i] << " ";
    cout << "\n";

    fill(v.begin(), v.end(),1);
    for(int i=0; i<10; i++) cout << v[i] << " ";
    cout << "\n";

}