#include <iostream>
#include <tuple> // tuple, tie

using namespace std;

int main() {
    // 선언
    tuple<int, int, int> tp;

    // 할당
    tp = make_tuple(1,2,3);

    // 꺼내기
    int a,b,c;
    tie(a,b,c) = tp;
    tie(ignore,ignore,c) = tp;
    // 꺼내기2
    a = get<0>(tp);
    b = get<1>(tp);

}