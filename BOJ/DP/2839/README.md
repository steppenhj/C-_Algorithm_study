Greedy로 풀 수 있다.

while(n>=0)인 동안 if(n%5==0)일 때 cnt+=(n/5);를 하고 cout << cnt << endl;한다.
이 때 끝내야지 n==0일 때도 처리할 수 있는 것이다. 
if문에 걸리지 않으면 n-=3; cnt++해준다. 

while문에서 if문에 걸리지 않고 return 되지 않는다면 바깥에서 cout << -1 << endl;하고 마무리한다.
