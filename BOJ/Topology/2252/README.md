위상정렬 문제. topology sort
"진입 차수 (Indegree) 라는 개념을 핵심으로 사용"
 진입차수란 어떤 학생(노드) 앞에 서야 하는 학생의 수
 indegree[B] = 3이면 B학생은 자기 앞에 3명이 모두 줄을 선 뒤에야 비로소 줄을 설 수 있다

 vector<int> adj[N+1]: "A뒤에 B가 와야 한다"는 순서 정보(간선)를 저장할 그래프
 int indegree[N+1]: 진입 차수(내 앞에 몇 명이 있는지)를 기록할 배열
 for(int i=0; i<M; i++){
   cin >> a >> b;
   adj[a].push_back(b);
   indegree[b]++;
}

줄을 세우기 위해 맨 처음에 설 수 있는 학생을 찾아야 한다.
맨 처음에 선다 -> "내 앞에 아무도 설 필요가 없다"
즉, 진입 차수(indegree)가 0인 학생들
for(int i=1; i<=N; i++){
  if(indegree[i]==0){
    q.push(i);
  }
}

이제 정렬을 수행하는데 queue를 이용하면 된다.
