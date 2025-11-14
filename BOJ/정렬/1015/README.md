우선 vector<pair<int, int>> vec(n)으로 인덱스를 한 묶음으로 저장함.
pair.first에는 값 저장. pair.second에는 원래 인덱스 (i)를 저장
예시) A=[2,1,3,1] -> vec = [{2,0}, {1,1}, {3,2}, {1,3}]
이 vec를 sort로 정렬한다.
정렬 후 vec = [{1,1}, {1,3}, {2,0}, {3,2}]

vector<int> P(n)을 만든다.
vec를 j=0부터 N-1까지 순회.
j=0: vec[0]={1,1}
j=1: vec[1]={1,3}
j=2: vec[2]={2,0}
j=3: vec[3]={3,2}

P = [2, 0, 3, 1]
