음  큐스택이라는 걸 처음 들었따. 큐 아니면 스택을 쓰라는 자료구조이다
잘 보면 큐만 걸러서 쓰면 되고, 스택은 변화가 없다

우선 n만큼 자료구조타입을 정해야 하므로
변수 vector<int> structure_types(n)을 만들었다.

그리고 vector<int> initial_values(n)을 만들어서 초기 값을 넣었다

그 후로 deque<int> dq;를 선언해서
structure_types[i]==0인 경우에만 dq.push_front(initial_values[i])를 했다

ex) 큐 스택 스택 큐 -> 1 2 3 4를 입력했다면
1 4만 들어간다

그리고 m만큼 new_element를 입력받는다
dq.push_back(new_element)를 한다
선입 선출이라서 push_back을 함
cout << dq.front() << " "
dq.pop_front(); 만 하면 끝

즉 1->스택은 버리고 하나의 큐만 생각한다**
