#include <iostream>
#include <algorithm>
#include <vector>
//           g++ -o main.exe main.cpp
//           .\main.exe
//    g++ -O2 -Wall -std=c++17 -o main main.cpp
//      ./main

using namespace std;

int dp[12];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4; i<=11; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    int t, n;
    cin >> t;

    while(t--){
        cin >> n;

        cout << dp[n] << endl;
    }
    return 0;
}
