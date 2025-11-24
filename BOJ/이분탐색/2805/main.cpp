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

    long long n, m;
    cin >> n >> m;
    vector<long long> tree(n);
    for(int i=0; i<n; i++){
        cin >> tree[i];
    }

    int left = 0;
    int right = *max_element(tree.begin(), tree.end());
    int result = 0;

    while(left <= right){
        long long mid = (left + right) / 2;
        long long sum = 0;
        for(int i=0; i<n; i++){
            if(tree[i] > mid){
                sum += tree[i] - mid;
            }

        }
        if(sum >= m){
            result = mid;
            left = mid + 1;
        } else{
            right = mid - 1;
        }
    }

    cout << result << "\n";

    return 0;
}
