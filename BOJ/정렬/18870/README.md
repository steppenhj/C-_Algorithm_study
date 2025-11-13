자, 압축 문제이다. 
sort해야 하는 건 보자마자 알 수 있다.
그리고 vector 2개 써야 되는 것도 알 수 있다. 

그런데, 나의 문제는 복제한 것을 sort했다해서 어떻게 기존의 것에 맞추냐이다.

vector<int> original(N);
vector<int> sorted_unique(N);
이렇게 선언했다고 하자.

입력을 알아서 받고. 정렬도 알아서 하자.

unique -> "삭제"가 아니라 "정리정돈"
[-10, -9, 2, 4, 4]의 벡터에 unique를 실행하면
[-10, -9, 2, 4 | 4] 가 됨. 뒷부분 [4]는 쓰레기 값
return value는 쓰레기 값이 시작되는 위치를 알려줌.

erase --> "삭제"
sorted_unique.erase(unique(...), sorted_unique.end());
-> unique(...)가 실행되고, 쓰레기 시작 위치(|)를 반환함.
-> erase가 그 쓰레기 시작위치부터 sorted_unique.end() 까지를 전부 삭제.
결과: [-10, -9, 2, 4]

**auto, lower_bound
sorted_unique [-10, -9, 2, 4]완성
original [2, 4, -10, 4, -9]을 보면서 답을 출력해야 함.
auto는 타입을 알아서 추측
lower_bound -> 정렬된 리스트에서 이진탐색 (O(log N)) 으로 값의 위치를 찾아줌
i=0: original[0] = 2 -> sorted_unique에서 2의 위치 -> 출력: 2
i=1: original[1] = 4 -> sorted_unique에서 3의 위치 -> 출력: 3
i=2: original[2] = -10 -> sorted_unique에서 0의 위치 -> 출력: 0
i=3: original[3] = 4 -> 출력: 3
i=4: original[4] = -9 -> 출력: 1
최종: 2 3 0 3 1
이렇게 됨!
