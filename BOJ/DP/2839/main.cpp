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

    int n;
    cin >> n;

    int cnt = 0;

    while(n >= 0){
        if(n%5==0){
            cnt += (n/5);
            cout << cnt << endl;
            return 0;
        }

        n -= 3;
        cnt++;
    }

    cout << -1 << endl;
    return 0;
}
