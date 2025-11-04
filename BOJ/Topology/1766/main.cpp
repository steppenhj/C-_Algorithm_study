기본적인 Topology에서 가능한 작은 수를 먼저 출력하라는 조건이 추가 되었다.
  원래는 queue를 사용했는데
  이제는 Priority Queue를 사용해야 한다.

priority_queue<int, vector<int>, greater<int>> pq;로 선언한다.

for(i 0부터 M까지) {a, b입력, adj[a].push_back(b)  indegree[b]++}
하고
for(i 1부터 N까지) {indegree가 0인 i에 대해 pq.push(i) }

while문 만들고 그 안에서 cur=pq.top()으로 선언. 그리고 result.push_back(cur) 찍고,
  for(int next : adj[cur]){ indegree[next]--  if(degree[next]==0){pq.push(next)}}
먼저 올 수 없는 것들에 대해서 하나씩 indegree를 1씩 뺴주고 0이 되면 pq에 push하는 것임.

  그리고 for(int node : result){cout << node << ' ' }하면 끝
