#include <iostream>
#include <queue>
#include <string>

//           g++ -o main.exe main.cpp
//           .\main.exe

using namespace std;

#define MAX 100

int N, M;
string maze[MAX];
int dist[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(){
    queue<pair<int, int>> q;

    q.push({0, 0});
    dist[0][0] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;

            if(maze[nx][ny] == '0') continue;

            if(dist[nx][ny] != 0) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> maze[i];
    }

    bfs();

    cout << dist[N-1][M-1] << '\n';

    return 0;
}
