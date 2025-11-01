익은 토마토가 1, 안 익은 토마토가 0, 토마토가 없으면 -1이다.
익은 토마토가 있는 위치에서 위,아래,왼쪽,오른쪽 총 4방향으로
안 익은 토마토가 익은 토마토가 된다(하루 지나면 0->1)

bfs()함수에서
int dx[4] = {1, -1, 0, 0}
int dy[4] = {0, 0, 1, -1}
으로 선언하고
while문 안에서 pair<int, int> cur = q.front()를 하고 바로 q.pop()을 한다.
4방향 모두 int nx = x + dx[i]를 해줌. y도 같음 (x=cur.first)
그리고 범위 밖, -1(토마토 없는 곳), days[nx][ny]!=-1인 경우 즉 조건 체크 3가지를 해주고
days[nx][ny] = days[x][y]+1을 해준다
q.push({nx, ny})를 한다

main에서 다 똑같이하고, bfs() 후에 maxDay만 체크해주면 된다
box[i][j]==0 && days[i][j]==-1일 때, -1 출력하는 것만 해주고
maxDay = max(maxDay, days[i][j])를 해주면 끝이다.

이 문제도 memset(days, -1, sizeof(days))를 한다
