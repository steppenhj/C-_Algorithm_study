그렇게 어려운 문제는 아니라고 느껴진다. 무조건 풀었어야 했는데, 침착하게 복기해보자.
우선 vector<map<int, int>> water; 로 받고 for문 쓰는 건 잘 했다.

start 가 널빤지로 커버치는 covered_len 보다 작으면 start를 covered_len으로 덮어준다.

그리고, start가 end 이상이라면 continue하여 넘어간다. (왜냐면 이전에 쓴 널빤지로 다음 start를 커버치는 경우도 있으니깐)

len = end - start로 초기화해주고, needed라는 필요한 널빤지를 만들어준다. 
needed = (len + L - 1) / L; 이다. 올림 나눗셈 공식이다.
