dfs로 4방향 돌아가면서 cnt를 추가하는 방식

T 입력 받고 while(T--) 동안 테스트 함
전역 변수로 받은 이차원 배열 int grid[50][50]에 
grid[y][x] = 1을 해줌. 이게 배추가 있는 곳의 위치를 적어두는 것임

그 후에 2중 for문으로 N, M까지 돌면서 if(grid[i][j]==1)일 때
dfs(i, j, N, M)을 돌리고 cnt++ 한다

다 하고는 T가 1이 아닐 수도 있으니깐
for문 만들어서 아래와 같이 함
for(int i=0; i<N; i++){
  fill(grid[i], grid[i]+M, 0);
}
