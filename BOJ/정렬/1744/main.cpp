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
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> pos;
    vector<int> neg;
    int one_cnt = 0;

    for(int i=0; i<n; i++){
        if(arr[i] > 1){
            pos.push_back(arr[i]);
        }
        else if(arr[i] < 1){
            neg.push_back(arr[i]);
        }
        else if(arr[i] == 1){
            one_cnt++;
        }
    }

    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());

    long long sum = 0;
    sum += one_cnt;

    for(int i=0; i<pos.size(); i+=2){
        if(i+1 < pos.size()){
            sum += (long long)pos[i] * pos[i+1];
        } else{
            sum += pos[i];
        }
    }

    for(int i=0; i<neg.size(); i+=2){
        if(i+1 < neg.size()){
            sum += (long long)neg[i] * neg[i+1];
        } else{
            sum += neg[i];
        }
    }

    cout << sum << '\n';

    return 0;
}
