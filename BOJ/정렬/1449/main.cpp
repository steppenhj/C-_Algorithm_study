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

    int N, L;
    cin >> N >> L;
    vector<int> positions(N);

    for(int i=0; i<N; i++){
        cin >> positions[i];
    }

    sort(positions.begin(), positions.end());

    int cnt = 0;
    int tape_end_pos = -1;

    for(int i=0; i<N; i++){
        int current_leak_pos = positions[i];

        if(current_leak_pos > tape_end_pos){
            cnt++;

            tape_end_pos = current_leak_pos + L - 1;
        }
    }

    cout << cnt << '\n';

    return 0;
}
