우선 핵심은 3개의 경우에 따라서 자료구조를 모두 나누는 것이다.
1보다 클 땐 vector<int> pos;, 
1일 땐 int one_cnt = 0;
1보다 작을 땐 vector<int> neg;

이렇게 하고 for문 안에서 알아서 push_back하면 된다.

양수는 내림차순, 음수는 오름차순 정렬한다.

그리고, pos, neg는 for문 안에서 i+=2 조건에서 계산처리한다.
