세 수의 합을 구해야 하고, 또 그것이 같은 벡터 안에 있어야 한다.
세 수의 합은 너무 커진다.

-> 두 수의 합과, 한 수 - 이항한 수 (벡터 안 위치)
이렇게 바꾸어서 푼다.

binary_search를 사용해야 해서 sort를 진행한다.

two_sum 벡터에 두 수의 합을 모두 넣어준다.
이것도 정렬해주기.

그 다음은 뒤에서 앞으로 target 만들고 (for문 2개)
if(binary_search(two_sum.begin(), two_sum.end(), target)){ cout << arr[i] << "\n"; return 0; }
이렇게 해준다. 

이렇게 하면 O(N^2 * log(N)) 이 된다.
