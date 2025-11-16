#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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
    vector<pair<int, int>> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(arr[0].second);

    for(int i=1; i<n; i++){
        int current_start = arr[i].first;
        int current_end = arr[i].second;

        if(pq.top() <= current_start){
            pq.pop();
            pq.push(current_end);
        }
        else{
            pq.push(current_end);
        }
    }

    cout << pq.size() << '\n';

    return 0;
}
