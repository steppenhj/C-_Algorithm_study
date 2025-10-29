#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;

  cout << n << endl;
  cout << 1 << endl;
}

#MenOfPassion 알고리즘 수행횟수와 최고차항 차수를 출력하는 문제이다
MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n
        sum <- sum + A[i]; # 코드1
    return sum;
}

위 코드는 for문을 돌며 배열 원소의 합을 구하는 알고리즘이다
입력에 제시된 n의 범위를 참고하면
시간 복잡도는 O(n)
수행 횟수는 n, 수행 시간은 항상 1이 된다
