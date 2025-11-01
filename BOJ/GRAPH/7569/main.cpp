#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <tuple>

//           g++ -o main.exe main.cpp
//           .\main.exe

using namespace std;

int N, M, H;
int box[101][101][101];
int dist[101][101][101];
queue<tuple<int, int, int>> q;

void bfs(){
    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};

    while(!q.empty()){
        tuple<int, int, int> cur = q.front();
        q.pop();

        int x = get<0>(cur);
        int y = get<1>(cur);
        int z = get<2>(cur);

        for(int i=0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(nx<0 || nx>= N || ny<0 || ny>=M || nz<0 || nz>=H){
                continue;
            }
            if(box[nx][ny][nz]==-1 || dist[nx][ny][nz] !=-1){
                continue;
            }

            dist[nx][ny][nz] = dist[x][y][z] + 1;
            q.push({nx, ny, nz});
        }

    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> H;

    memset(dist, -1, sizeof(dist));

    for(int k=0; k<H; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> box[i][j][k];

                if(box[i][j][k]==1){
                    q.push({i, j, k});
                    dist[i][j][k] = 0;
                }
            }
        }
    }

    bfs();

    int maxDay = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<H; k++){
                if(box[i][j][k]==0 && dist[i][j][k]==-1){
                    cout << -1 << "\n";
                    return 0;
                }

                maxDay = max(maxDay, dist[i][j][k]);
            }
        }
    }

    cout << maxDay << '\n';

    return 0;
}
