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

    int N;
    cin >> N;
    
    vector<int> arr(N);
    int max_request = 0;

    for(int i=0; i<N; i++){
        cin >> arr[i];
        if(arr[i] > max_request) max_request = arr[i];
    }

    long long M;
    cin >> M;

    int left = 0;
    int right = max_request;
    int result = 0;

    while(left <= right){
        int mid = (left + right) / 2;
        long long sum = 0;

        for(int i=0; i<N; i++){
            sum += min(arr[i], mid);
        }

        if(sum <= M){
            result = mid;
            left = mid + 1;
        } else{
            right = mid - 1;
        }
    }
    
    cout << result << "\n";

    return 0;
}
