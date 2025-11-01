#include <iostream>
#include <queue>
#include <cstring>

//           g++ -o main.exe main.cpp
//           .\main.exe

using namespace std;

int dist[300][300];
int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {1, -1, 2, 2, 1, -1, -2, -2};
pair<int, int> startPos, targetPos;
int l;

void bfs(){
    queue<pair<int, int>> q;
    q.push(startPos);
    dist[startPos.first][startPos.second] = 0;

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        int x=cur.first;
        int y=cur.second;

        if(x==targetPos.first && y==targetPos.second){
            cout << dist[x][y] << '\n';
            return;
        }

        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || nx>=l || ny<0 || ny>=l) continue;
            if(dist[nx][ny]!=-1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        cin >> l;
        cin >> startPos.first >> startPos.second;
        cin >> targetPos.first >> targetPos.second;

        if(startPos == targetPos){
            cout << 0 << '\n';
            continue;
        }

        memset(dist, -1, sizeof(dist));

        bfs();
    }

    return 0;
}
