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

    int N, L;
    cin >> N >> L;

    vector<pair<int, int>> water;

    for(int i=0; i<N; i++){
        int start, finish;
        cin >> start >> finish;
        water.push_back({start, finish});
    }

    sort(water.begin(), water.end());

    int cnt = 0;
    int covered_len = 0;

    for(int i=0; i<N; i++){
        int start = water[i].first;
        int end = water[i].second;

        if(start < covered_len){
            start = covered_len;
        }

        if(start >= end){
            continue;
        }

        int len = end - start;

        int needed = (len + L - 1) / L;

        cnt += needed;

        covered_len = start + (needed * L);
    }

    cout << cnt << '\n';
    
    return 0;
}
