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
    vector<int> original(N);
    vector<int> sorted_unique(N);

    for(int i=1;i <N; i++){
        cin >> original[i];
        sorted_unique[i] = original[i];
    }

    sort(sorted_unique.begin(), sorted_unique.end());
    sorted_unique.erase(unique(sorted_unique.begin(), sorted_unique.end()), sorted_unique.end());

    for(int i=1; i<=N; i++){
        auto it = lower_bound(sorted_unique.begin(), sorted_unique.end(), original[i]);

        cout << (it - sorted_unique.begin()) << ' ';
    }
    cout << '\n';

    return 0;
}
