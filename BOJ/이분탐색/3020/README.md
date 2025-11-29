vector<int> bottom;
vector<int> top; 
으로 아래와 위를 따로 받는다. 이 정도는 할 수 있지.
for문 안에서 if(i%2==0)으로 따로 처리하면 되니깐.

그 다음 sort까지도 쉽다.
int min_obstacles=N+1까지도 솔직히 쉽지

이제, for문에서 N이 아니라 H기준으로 잡아야 하는데 이게 헷갈린다.
이 이후에도 lower_bound 함수를 써야 한다.
int bottom_idx = lower_bound(bottom.begin(), bottom.end(), h) - bottom.begin();
int top_idx = lower_bound(top.begin(), top.end(), H-h+1) - top.begin();
여기에서 탑은 H-h+1이면 장애물에 부딪히는 것 주의.
bottom.begin()과 top.begin()을 다시 빼는 이유는 int로 사용하기 위함이다.
(원래는 주소라서 못 씀)

if(obstacles < min_obstacles){ min_obstacles=obstacles;
cnt=1;} 여기서 cnt=1은 이제 최소가 되는 구간(문제용어임)을 찾았으니 1로 잡아줌.
그리고 else if(obstacles==min_obstacles) cnt++; 은 똑같은 걸 여러개 찾은 경우임.
