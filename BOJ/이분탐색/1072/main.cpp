#include <iostream>
#include <algorithm>
#include <vector>
//           g++ -o main.exe main.cpp
//           .\main.exe
//    g++ -O2 -Wall -std=c++17 -o main main.cpp
//      ./main

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long x, y;
    cin >> x >> y;

    long long z = (y * 100) / x;

    if(z >= 99){
        cout << -1 << "\n";
        return 0;
    }
    
    long long left = 1;
    long long right = x;
    long long ans = -1;

    while(left <= right){
        int mid = (left + right) / 2;

        int val = (y + mid) * 100 / (x + mid);
        if(val > z){
            ans = mid;
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
