이분탐색 실버 수준의 문제이다.
시원하게 풀질 못했다. 이분탐색 공부는 얼마 안 하긴 했는데, 이거 한 1주일 이상은 더 잡아야 마스터 할 것 같다.

우선, 이 문제는 mid 쓰고 그냥 일반적인 문제였다.
하나 기억하면 좋겠는 것은
vector 입력 받으면서 바로 max_request를 같이 검사해서 max값을 정하는 거다. 
이게 뒤에 따로 하는 것보다 코드도 짧고 나중에 풀이도 빠를 것 같다.

솔직히 while문 안에서는 특별할 게 없다.
while(left <= right){
  int mid = (left + right) / 2;
  long long sum = 0;
  여기 까진 당연한 거.

  for(int i=0; i<N; i++){
    sum += min(arr[i], mid);
    여기가 좀 특이하지. 이러면 계속 작게 더 하잖아.
    120 110 140 150 입력 받으면, right = 150
    mid는 우선 75로 시작. 계속 75가 선택될 것.
    그럼 아래 코드

    if(sum <= M){
      result = mid;
      left = mid + 1;
    } else{
        right = mid - 1;
    }
    이렇게 된다. 우선 초반에는 left = mid + 1에 계속 걸려서 
    왔다 갔다 하면서 맞춰진다.
  }
