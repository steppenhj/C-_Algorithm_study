#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <tuple>

//           g++ -o main.exe main.cpp
//           .\main.exe

using namespace std;
int N, M;
int x, y, u, v;
int dist[101];
int link[101];

queue<int> q;

void bfs(){
    q.push(1);
    dist[1] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == 100) {
            cout << dist[100];
            break;
        }

        for(int i=1; i<=6; i++){
            int next_try_pos = cur + i;

            if(next_try_pos > 100) continue;

            int final_pos = link[next_try_pos]; 

            if(dist[final_pos] == -1){
                dist[final_pos] = dist[cur] + 1;
                q.push(final_pos);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dist, -1, sizeof(dist));
    for(int i=1; i<=100; i++){
        link[i] = i;
    }

    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> x >> y;
        link[x] = y;
    }
    for(int i=0; i<M; i++){
        cin >> u >> v;
        link[u] = v;
    }

    bfs();

    return 0;
}
