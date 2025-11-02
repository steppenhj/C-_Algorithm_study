일반적인 미로 찾기 문제에서 조건이 하나 생겼다.
0: 갈 수 있는 길, 1: 벽
추가된 조건 -> 벽을 한 번 깰 수 있다.

이 부분을 처리하기 위해 코드를 조금 다르게 짜야한다.

string map[MAX];는 같다
int dist[MAX][MAX][2]; 이 부분에 [2]로 
[0]-> 벽을 부수지 않은 최단 거리
[1]-> 벽을 한 번 부순 최단 거리가 된다

queue<tuple<int, int, int>> q;
이건 저번에 사용해본 것이고, q.push({0, 0, 0}); 이것도.
dist[0][0][0]=1 이것도.

신기한 건 while문 안에서 tie(x, y, broken) = q.front()를 사용했다.
그리고 
1. 다음 칸이 길('0')과 2. 다음 칸이 벽('1')이고 아직 벽 안 부숨으로 나눈다
if(map[nx][my]=='0' && dist[nx][ny][broken]==0)
+
if(map[nx][ny]=='1' && broken==0 && dist[nx][ny][1] ==0)

출력 부분도 조금 다르다
int ans0 = dist[N-1][M-1][0];
int ans1 = dist[N-1][M-1][1];
if(ans0 == 0 && ans1 == 0) return -1;
else if(ans0==0) return ans1;
else if(ans1==0) return ans0;
else return min(ans0, ans1);
이렇게 했다
