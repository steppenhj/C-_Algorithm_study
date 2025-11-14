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

    vector<pair<int, int>> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i].first;
        vec[i].second = i;
    }

    sort(vec.begin(), vec.end());

    vector<int> P(n);

    for(int j=0; j<n; j++){
        int original_index = vec[j].second;
        int new_rank = j;
    
        P[original_index] = new_rank;
    }

    for(int i=0; i<n; i++){
        cout << P[i] << ' ';
    }
    cout << '\n';


    return 0;
}
