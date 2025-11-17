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
    vector<long> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int cnt = 0;
    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        long target = arr[k];

        int left = 0;
        int right = n-1;

        while(left < right){
            if(left == i){
                left++;
                continue;
            }
            if(right == i){
                right--;
                continue;
            }

            long sum = arr[left] + arr[right];

            if(sum == target){
                cnt++;
                break;
            } else if(sum < target){
                left++;
            } else{
                right--;
            }
        }
    }

    cout << cnt << 

    return 0;
}
