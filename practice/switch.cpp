#include <iostream>
using namespace std;

int main() {
    int n = 3;
    switch(n)
    {
        case 1:
            cout << "1" << "\n";
            break;
        case 3:
            cout << "3" << "\n";
            break;
        default:
            cout << "Unknown" << "\n";
            break;
    }
}