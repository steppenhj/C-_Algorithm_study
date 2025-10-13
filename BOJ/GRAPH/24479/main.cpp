#include <iostream>
#include <vector>
#include <algorithm>
//           g++ -o main.exe main.cpp
//           .\main.exe

using namespace std;

int n, m, r;

vector<int> table[100001];
int isVisited[100001] = {0, };
int cnt = 1;

void dfs(int v){
    isVisited[v] = cnt++;

    for(int to : table[v]){
        if(isVisited[to] == 0){
            dfs(to);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;

        table[u].push_back(v);
        table[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        sort(table[i].begin(), table[i].end());
    }

    dfs(r);

    for(int i=1; i<=n; i++){
        cout << isVisited[i] << '\n';
    }
    
    return 0;
}
