#include <vector>
#include <queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 전형적인 BFS 제일 쉬운 문제.
// 오늘로서 이 문제는 무조건 풀 수 있도록 한다.
// 최단거리는 BFS
int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && nx<n && ny>=0 && ny<m && maps[nx][ny]==1){
                maps[nx][ny] = maps[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    int answer = maps[n-1][m-1];
    
    answer = (answer == 1) ? -1 : answer;
    
    return answer;
}
