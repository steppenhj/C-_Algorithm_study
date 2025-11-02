#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <tuple>
#include <algorithm>
//           g++ -o main.exe main.cpp
//           .\main.exe

using namespace std;

#define MAX 1001
int N, M;
string map[MAX];
int dist[MAX][MAX][2];
// dist[x][y][0] : 벽을 부수지 않은 최단 거리
// dist[x][y][1] : 벽을 한 번 부순 최단 거리

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(){
    memset(dist, 0, sizeof(dist));

    queue<tuple<int, int, int>> q;

    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while(!q.empty()){
        int x, y, broken;
        tie(x, y, broken) = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0||nx>=N || ny<0||ny>=M) continue;
            
            // 1.다음 칸이 길('0')
            if(map[nx][ny] == '0' && dist[nx][ny][broken]==0){
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.push({nx, ny, broken});
            }

            //2. 다음 칸이 벽('1') && 아직 변 안 부숨
            if(map[nx][ny] == '1' && broken==0 && dist[nx][ny][1]==0){
                dist[nx][ny][1] = dist[x][y][0] + 1;
                q.push({nx, ny, 1});
            }
        }
    }

    int ans0 = dist[N-1][M-1][0];
    int ans1 = dist[N-1][M-1][1];

    if(ans0 == 0 && ans1 == 0) return -1;
    else if (ans0==0) return ans1;
    else if (ans1==0) return ans0;
    else return min(ans0, ans1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> map[i];
    }

    cout << bfs() << '\n';

    return 0;
}
