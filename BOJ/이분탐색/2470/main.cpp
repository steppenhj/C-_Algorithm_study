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
    
    vector<long long> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n-1;

    long long min_abs = 2400000000;

    int ans_left = 0;
    int ans_right = 0;

    while(left < right){
        long long sum = arr[left] + arr[right];

        if(abs(sum) < min_abs){
            min_abs = abs(sum);
            ans_left = arr[left];
            ans_right = arr[right];

            if(sum == 0) break;
        }

        if(sum < 0){
            left++;
        }else{
            right--;
        }
    }

    cout << ans_left << " " << ans_right << "\n";

    return 0;
}
