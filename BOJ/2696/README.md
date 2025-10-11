Priority Queue 문제이다.
이 문제가 특이한 것은 maxheap과 minheap을 둘 다 만들어서 두 개의 size()를 비교해야 하는 것이다.
중앙값을 출력하기 위해서, maxheap.size()==minheap.size() 일 때는 maxheap.push(x);을 했다.

그 후에는 maxheap.top과 minheap.top을 비교하면서 지속적으로 minheap에 더 큰 수를 올려준다.

이제는 vector<int> ans;에 maxheap.top()을 push_back 해주고 출력한다.

핵심 아이디어는 중앙값을 위해 maxheap과 minheap을 둘 다 사용하는 것이다.
===========================================================

priority_queue<int, vector<int>> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;
