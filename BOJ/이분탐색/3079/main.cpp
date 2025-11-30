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
    long long m;
    cin >> n >> m;

    vector<long long> arr(n);
    long long max_time = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i] > max_time) max_time = arr[i];
    }

    long long left = 1;
    long long right = max_time * m;
    long long ans = right;

    while(left <= right){
        long long mid = (left+right) / 2;
        long long sum = 0;

        for(int i=0; i<n; i++){
            sum += (mid / arr[i]);

            if(sum >= m) break;
        }

        if(sum >= m){
            ans = mid;
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
