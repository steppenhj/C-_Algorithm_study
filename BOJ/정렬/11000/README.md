당연히 정렬 후, gridy로 풀어야 했다.
priority_queue<int, vector<int>, greater<int>> pq; 로 우선순위큐를 선언하고
pq.push(arr[0].second)를 해준다. 이건 pq에 첫 번째 강의 종료 시간을 넣는 것이다.

for 반복문 안에서
int current_start = arr[i].first;
int current_end = arr[i].end;
로 선언한다.
if(pq.top() <= current_start){ pq.pop(); pq.push(current_end); }
else { pq.push(current_end); }
한다. 
즉, 가장 빨리 비는 강의실-pq.top()과 i번째 강의의 시작인 current_start를 비교해서, 
비는 강의실이 더 빠르면 pq.pop(); pq.push(current_end)를 한다.
가장 빨리 비는 강의실보다도 i번째 강의실이 먼저 시작한다면
그냥 바로 pq.push(current_end)한다.
