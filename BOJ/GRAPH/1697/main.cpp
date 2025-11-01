#include <iostream>
#include <queue>
#include <cstring>

//           g++ -o main.exe main.cpp
//           .\main.exe

using namespace std;

#define MAX 100001
int dist[MAX];
int N, K;

void bfs(int startNode){
    queue<int> q;

    q.push(startNode);
    dist[startNode] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == K) break;

        int next_pos[3] = {cur-1, cur+1, cur*2};

        for(int i=0; i<3; i++){
            int next = next_pos[i];

            if(next<0 || next>=MAX) continue;

            if(dist[next] == -1){
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    memset(dist, -1, sizeof(dist));

    bfs(N);

    cout << dist[K] << "\n";

    return 0;
}
