#include <iostream>
#include <cstdlib>
//           g++ -o main.exe main.cpp
//           .\main.exe
//    g++ -O2 -Wall -std=c++17 -o main main.cpp
//      ./main

using namespace std;

int arr[15];
int N, cnt = 0;

bool is_promising(int k){
    for(int i=0; i<k; i++){
        if(arr[i] == arr[k]){
            return false;
        }
        if(abs(k-i) == abs(arr[k] - arr[i])){
            return false;
        }
    }

    return true;
}

void func(int k){
    if(k==N){
        cnt++;
        return;
    }

    for(int i=0; i<N; i++){
        arr[k] = i;

        if(is_promising(k)){
            func(k+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    func(0);

    cout << cnt << '\n';

    return 0;
}
