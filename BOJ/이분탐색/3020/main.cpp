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

    int N, H;
    cin >> N >> H;
    vector<int> bottom;
    vector<int> top;

    for(int i=0; i<N; i++){
        if(i%2==0){
            int b;
            cin >> b;
            bottom.push_back(b);
        } else{
            int t;
            cin >> t;
            top.push_back(t);
        }
    }

    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());

    int min_obstacles = N+1;
    int cnt = 0;

    for(int h=1; h<=H; h++){
        int bottom_idx = lower_bound(bottom.begin(), bottom.end(), h) - bottom.begin();
        int top_idx = lower_bound(top.begin(), top.end(), H-h+1) - top.begin();

        int obstacles = (bottom.size() - bottom_idx) + (top.size() - top_idx);

        if(obstacles < min_obstacles){
            min_obstacles = obstacles;
            cnt = 1;
        } else if(obstacles == min_obstacles){
            cnt++;
        }

    }

    cout << min_obstacles << " " << cnt << "\n";

    return 0;
}
