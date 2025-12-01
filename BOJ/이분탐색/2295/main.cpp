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
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int> two_sum;
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            two_sum.push_back(arr[i] + arr[j]);
        }
    }

    sort(two_sum.begin(), two_sum.end());

    for(int i=N-1; i>=0; i--){
        for(int j=0; j<N; j++){

            int target = arr[i] - arr[j];

            if(target <= 0) continue;

            if(binary_search(two_sum.begin(), two_sum.end(), target)){
                cout << arr[i] << "\n";
                return 0;
            }
        }
    }

    return 0;
}
