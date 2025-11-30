이거 진짜 대박이다. 제대로 이해하고 내 걸로 만들자.

일단 문제가 시간을 구하라는 거니깐 mid를 시간으로 둬야 한다.
그러니깐 long long left = 1; long long right = max_time * m (젤 오래걸리는 심사대랑 인원수의 곱)
이렇게 표현해야 제일 작은 시간 1분과 젤 긴 시간을 표현할 수 있다.

그 다음은 똑같다. while문 만들고 그 안에 for문 만들어서 하면 된다.

시간을 mid로 정하고 입국심사대 arr[i]로 나누는 걸 다 더해서 그게 인원수를 넘는지, 못 넘는지로 left, right의 기준을 계속 처리하면 된다.

long long sum =0을 정의해두고, for문 안에서 sum += (mid/arr[i])로 하고, if(sum>=m) break해준다.
그 이후에 sum과 인원수의 크기를 비교하여 left혹은 right를 바꿔준다.
