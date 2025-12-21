#include <iostream>
#include <algorithm>
#include <vector>
//           g++ -o main.exe main.cpp
//           .\main.exe
//    g++ -O2 -Wall -std=c++17 -o main main.cpp
//      ./main

using namespace std;

long long dp[201][201];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    for(int i=0; i <= N; i++){
        dp[1][i] = 1;
    }

    for(int i=0; i<=K; i++){
        dp[i][0] = 1;
    }

    for(int k=2; k<=K; k++){
        for(int n=1; n<=N; n++){
            dp[k][n] = dp[k-1][n] + dp[k][n-1];
            dp[k][n] %= 1000000000;
        }
    }

    cout << dp[K][N] << endl;

    return 0;
}
