#include <iostream>
#include <vector>
#include <typeinfo> // https://bab2min.tistory.com/639
using namespace std;

typedef unsigned int uint;

int main() {
    /*
        vector declaration and initialize
        내가 이용할 방법:
            sixth, seventh, eighth
    */ 
    vector<int> first;
    vector<int> second (4,100); // four ints with value 100
    vector<int> third (second.begin(), second.end()); // iterating
    vector<int> fourth (third); // a copy of third
    vector<int> fifth{11, 23, 26, 30};
    vector<int> sixth = {1,2,3,4,5};
    vector<int> seventh = vector<int>();
    vector<vector<int>> eighth = vector(7, vector<int>(7,0));

    cout << typeid(vector<int>()).name() << "\n";
    cout << typeid(vector<vector<int>>()).name() << "\n";
        // https://bab2min.tistory.com/639
    /*
        array to vector
    */
    int myints[] = {16, 2, 77, 29};
        // ver1
    vector<int> vec1;
    vec1.insert(vec1.end(), myints, myints+( sizeof(myints) / sizeof(int) ));

        // ver2
    vector<int> vec2(myints, myints+(sizeof(myints)/sizeof(int)));

    /*
        Iterate
    */
        // ver1
    for(uint i=0; i<vec1.size(); i++) {
        cout << vec1[i] << " ";
    }
    cout << "\n";

        // ver2
    for(auto & el : vec1) {
        cout << el << " ";
    }
    cout << "\n";

        // ver 3
    for(auto it = vec1.begin(); it != vec1.end(); it++)
        cout << *it << " ";
        // ver4
    vector<int>::iterator iter = vec1.begin();
    for(; iter < vec1.end(); iter++) {
        cout << *iter << " ";
    }

}