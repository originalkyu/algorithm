/*
문제: 2309 일곱난장이
링크: https://www.acmicpc.net/problem/2309
날짜: 221007
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    vector<int> v;
    int num;
    int sum=0;
    for(int i = 0; i < 9; i++) {
        cin >> num;
        v.push_back(num);
        sum+=num;
    }  
    sum-=100;

    int not1, not2;
    for(int i = 0; i < 8; i++) {
        for(int j=i+1; j < 9; j++) 
            if(v[i]+v[j]==sum) {
                not1 = v[i];
                not2 = v[j];
                sort(v.begin(), v.end());
                for(int k=0; k<9; k++) {
                    if(v[k]!=not1 && v[k]!=not2)
                    cout << v[k] << '\n';
                }

                return 0;
            }

    }
    
    return 1;

}