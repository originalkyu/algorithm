#include <iostream>
#include <utility>
using namespace std;

// typedef [original] [new name]
typedef unsigned int uint;

struct Person {
    int age, height;
};
typedef Person p;


typedef pair<int,int> pii;

int main() {
    pii p1 = {1,2};
    cout << p1.first << " " << p1.second << "\n";
}