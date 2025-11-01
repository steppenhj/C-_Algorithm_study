2차원의 미로 문제와 유사하다.

이건 1차원이다. 최단시간은 최단거리와 똑같다. bfs로 푼다

memset(dist, -1, sizeof(dist));로 dist를 모두 -1로 초기화한다
이유는 여기에서 시작점이 0이라서 0을 비었다는 의미로 쓸 수가 없다

void bfs(int startNode) 로 시작해서
q.push(startNode);, dist[startNode]=0으로 시작한다
시작점을 큐에 넣고, 시작점을 0으로 설정한다

while문 시작해서,
next_pos[3] = {cur-1, cur+1, cur*2} 이렇게 3개 넣는다
for문 3까지 해서 int next = next_pos[i]로 한다.
if(next<0 || next>=MAX) continue한다

if(dist[next]==-1)이면
dist[next] = dist[cur] + 1, q.push(next)를 한다
cur 은 int cur = q.front()이다.
