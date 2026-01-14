#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
//           g++ -o main.exe main.cpp
//           .\main.exe
//    g++ -O2 -Wall -std=c++17 -o main main.cpp
//      ./main

using namespace std;

int get_dist(const string& a, const string& b){
    int dist = 0;
    for(int i=0; i<4; i++){
        if(a[i] != b[i]) dist++;
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;

        vector<string> members(N);
        for(int i=0; i<N; i++){
            cin >> members[i];
        }

        if(N>32) {
            cout << 0 << '\n';
            continue;
        }

        int min_dist = 10000;

        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                for(int k=j+1; k<N; k++){
                    int current_dist = get_dist(members[i], members[j]) +
                                        get_dist(members[j], members[k]) +
                                        get_dist(members[k], members[i]);

                    min_dist = min(min_dist, current_dist);
                }
            }
        }
        cout << min_dist << '\n';

    }
    
    return 0;
}
