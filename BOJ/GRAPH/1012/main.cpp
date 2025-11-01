#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

//           g++ -o main.exe main.cpp
//           .\main.exe

using namespace std;

int grid[50][50];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int N, int M){
    grid[x][y] = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<N && ny>=0 && ny<M){
            if(grid[nx][ny] == 1){
                dfs(nx, ny, N, M);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    int M, N, K, cnt=0;
    while(T--){
        cin >> M >> N >> K;
        for(int i=0; i<K; i++){
            int x, y;
            cin >> x >> y;
            grid[y][x] = 1;
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, N, M);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
        cnt = 0;
        for(int i=0; i<N; i++){
            fill(grid[i], grid[i]+M, 0);
        }
    }

    return 0;
}
