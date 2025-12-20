#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
//           g++ -o main.exe main.cpp
//           .\main.exe
//    g++ -O2 -Wall -std=c++17 -o main main.cpp
//      ./main

using namespace std;

int dp[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    int len1 = s1.length();
    int len2 = s2.length();

    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[len1][len2] << endl;

    return 0;
}
