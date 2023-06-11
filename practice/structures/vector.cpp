#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
        vector declaration and initialize
    */ 
    vector<int> first;
    vector<int> second (4,100); // four ints with value 100
    vector<int> third (second.begin(), second.end()); // iterating
    vector<int> fourth (third); // a copy of third

    /*
        vector copy
    */
    int myints[] = {16, 2, 77, 29};
        // ver1
    vector<int> vec1;
    vec1.insert(vec.end(), myints, myints+( sizeof(myints) / sizeof(int) ))

        // ver2
    vector<int> vec2(myints, myints+(sizeof(myints)/sizeof(int)))

    /*
        Iterate
    */
        // ver1
    for(int i=0; i<vec1.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";

        // ver2
    for (auto & el : vec1) {
        cout << el << " ";
    }
    cout << "\n";
}