/*
c++20
*/
#include <iostream>
#include <string> // string
#include <format>
using namespace std;

int main() {
    string a {format("{0}, {1}!", "hello", "world")};
}