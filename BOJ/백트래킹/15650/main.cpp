#include <iostream>
//           g++ -o main.exe main.cpp
//           .\main.exe
//    g++ -O2 -Wall -std=c++17 -o main main.cpp
//      ./main

using namespace std;

int N, M;
int arr[10];

void func(int k){
    if(k==M){
        for(int i=0; i<M; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int start = 1;
    if(k!=0){
        start = arr[k-1] + 1;
    }

    for(int i=start; i<=N; i++){
        arr[k] = i;
        func(k+1);
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    func(0);

    return 0;
}
