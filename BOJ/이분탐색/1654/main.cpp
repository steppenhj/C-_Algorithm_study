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
    long long k;
    cin >> n >> k;

    vector<long long> arr(n);
    long long max_val = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        max_val = max(max_val, arr[i]);
    }

    long long left = 1;
    long long right = max_val;
    long long answer = 0;

    while(left <= right){
        long long mid = (left + right) / 2;
        long long cnt = 0;

        for(int i=0; i<n; i++){
            cnt += arr[i] / mid;
        }

        if(cnt >= k){
            answer = mid;
            left = mid + 1;
        } else{
            right = mid - 1;
        }
    }

    cout << answer << "\n";

    return 0;
}
