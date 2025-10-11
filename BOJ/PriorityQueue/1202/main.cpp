#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

//           g++ -o main.exe main.cpp
//           .\main.exe

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> backPack(n); //(무게, 가격)
    vector<int> C(k); //최대무게

    for(int i=0; i<n; i++){
        cin >> backPack[i].first >> backPack[i].second;
    }
    for(int i=0; i<k; i++){
        cin >> C[i];
    }

    sort(backPack.begin(), backPack.end());
    sort(C.begin(), C.end());

    priority_queue<int> pq; //

    long long ans = 0;
    int idx = 0;
    for(int i=0; i<k; i++){
        while(idx < n && backPack[idx].first <= C[i]){
            pq.push(backPack[idx++].second);
        }
        if(pq.size()){
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
    
    return 0;
}
