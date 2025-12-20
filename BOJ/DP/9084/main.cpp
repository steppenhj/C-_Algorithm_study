#include <iostream>
#include <algorithm>
#include <cstring>
//           g++ -o main.exe main.cpp
//           .\main.exe
//    g++ -O2 -Wall -std=c++17 -o main main.cpp
//      ./main

using namespace std;

int dp[10001];
int coins[21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, M;
    cin >> T;

    while(T--){
        cin >> N;

        for(int i=1; i<=N; i++){
            cin >> coins[i];
        }

        cin >> M;

        memset(dp, 0, sizeof(dp));

        dp[0] = 1;

        for(int i=1; i<=N; i++){
            int coin = coins[i];

            for(int j=coin; j<=M; j++){
                dp[j] = dp[j] + dp[j-coin];
            }
        }

        cout << dp[M] << "\n";
    }

    return 0;
}
