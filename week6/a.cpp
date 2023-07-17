#include <iostream>
using namespace std;
int main() {
    int x = 50;
    int y = 29;

    double a = 100*( (double)y / (double)x);
    double b = 58;
    double c = 0.58 * 100;

    bool c1 = (int)a > (int)b;
//    cout << a << " " << b << "\n";
//    cout << (int)a << " " << (int)b << "\n";
    cout << fixed;
    cout.precision(20);
    cout << a << "\n";
    cout << (int)a << "\n";
    cout << c << "\n";
}