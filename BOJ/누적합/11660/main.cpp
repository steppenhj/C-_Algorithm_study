#include <iostream>
#include <vector>
//           g++ -o main.exe main.cpp
//           .\main.exe
//    g++ -O2 -Wall -std=c++17 -o main main.cpp
//      ./main

using namespace std;

int arr[1025][1025], dp[1025][1025];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
            dp[i][j] = dp[i-1][j]+dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
        }
    }
    int x1,y1,x2,y2;
    int ans;
    for(int i=0; i<M; i++){
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        ans = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        cout << ans << '\n';
    }

    return 0;
}
