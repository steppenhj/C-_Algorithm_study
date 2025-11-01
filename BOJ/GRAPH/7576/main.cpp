#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

//           g++ -o main.exe main.cpp
//           .\main.exe

using namespace std;

int N, M;
int box[1000][1000];
int days[1000][1000];
queue<pair<int, int>> q;

void bfs(){
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(box[nx][ny] == -1 || days[nx][ny] != -1) continue;

            days[nx][ny] = days[x][y] + 1;
            q.push({nx, ny});
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;

    memset(days, -1, sizeof(days));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> box[i][j];

            if(box[i][j] == 1){
                q.push({i, j});
                days[i][j] = 0;
            }
        }
    }

    bfs();

    int maxDay = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(box[i][j] == 0 && days[i][j] == -1){
                cout << -1 << '\n';
                return 0;
            }

            maxDay = max(maxDay, days[i][j]);
        }
    }

    cout << maxDay << '\n';

    return 0;
}
