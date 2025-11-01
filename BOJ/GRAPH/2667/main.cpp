#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

//           g++ -o main.exe main.cpp
//           .\main.exe

using namespace std;

#define MAX 26

int n, cnt = 0;
string arr[MAX];
bool visited[MAX][MAX] = {0, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> result;

void bfs(int x, int y){
    queue<pair<int, int>> q;

    q.push({x, y});
    visited[x][y] = true;
    cnt++;

    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = a + dx[i];
            int ny = b + dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<n && visited[nx][ny]==false && arr[nx][ny]=='1'){
                q.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]=='1' && visited[i][j]==false){
                cnt=0;
                bfs(i, j);
                result.push_back(cnt);
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for(int i=0; i<result.size(); i++){
        cout << result[i] << "\n";
    }

    return 0;
}
