#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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

    map<int, int> before_rank;

    for(int i=0; i<n; i++){
        int player;
        cin >> player;
        before_rank[player] = i;
    }

    int max_up = -2000000000;

    vector<pair<int, int>> changes;

    for(int i=0; i<n; i++){
        int player;
        cin >> player;

        int diff = before_rank[player] - i;

        changes.push_back({player, diff});

        if(diff > max_up){
            max_up = diff;
        }
    }

    for(int i=0; i<n; i++){
        if(changes[i].second == max_up){
            cout << changes[i].first << " ";
        }
    }

    return 0;
}
