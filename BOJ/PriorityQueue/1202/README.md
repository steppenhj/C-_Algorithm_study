문제는 보석 N개, 가방 K개
보석 N개의 각각의 무게 M, 가격 V
가방 각각의 최대 무게 C
를 고려해서 푸는 문제이다.

Priority Queue와 Greedy로 풀면 된다.

먼저 
vector<pair<int, int>> backPack(n) 으로 n개의 가방에 대해 무게와 가격을 받는다.
vector<int> C(k)로 가방의 각각의 최대 무게도 받는다.

그 후로는 Greedy를 사용하기 위해 
sort(backPack.begin(), backPack.end());
sort(C.begin(), C.end()); 를 진행했다.

priority_queue<int> pq;를 만들고 i<k(가방수)인 상황에서 
backPack[idx].first <= C[i] 인 상황 동안     (보석이 가방보다 가벼울 때)
pq.psuh(backPack[idx++].second)를 한다.      (보석의 가격을 pq에 넣음)
pq.size()가 참일 동안 pq.top()을 ans에 더해주고 pq.pop()을 반복한다.
ans를 출력하면 끝

여기에서 실수는 backPack으로 정의한 것이다. 보석을 정의하는 것인데 변수명을 헷갈리게 가방으로 선택했다.
backPack -> jewels or gems 로 했으면 좋아겠다.

문제 핵심: 가벼운 보석은 무거운 가방에도 들어갈 수 있지만, 무거운 보석은 가벼운 가방에 들어갈 수 없다. 
따라서 용량이 작은 가방에 담을 수 있는 가장 비싼 보석을 넣자.
