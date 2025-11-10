#include <iostream>
#include <string>
#include <vector>
//           g++ -o main.exe main.cpp
//           .\main.exe
//    g++ -O2 -Wall -std=c++17 -o main main.cpp
//      ./main

using namespace std;

int sum[26][200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    cin >> S;

    int q;
    cin >> q;

    int len = S.length();

    sum[S[0] - 'a'][0] = 1;
    
    for(int i=1; i<len; i++){
        for(int j=0; j<26; j++){
            sum[j][i] = sum[j][i-1];
        }
        sum[S[i] - 'a'][i]++;
    }

    for(int i=0; i<q; i++){
        char alpha;
        int l, r;
        cin >> alpha >> l >> r;

        int char_index = alpha - 'a';

        int cnt = cum[char_index][r];

        if(l > 0){
            count -= sum[char_index][l-1];
        }

        cout << cnt << '\n';
    }

    return 0;
}
