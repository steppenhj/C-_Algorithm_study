퀸을 놓는 문제이다. 
한 행에 퀸을 놓으면 어차피 해당 행에는 퀸을 놓지 못한다.
함수는 2개 사용했다.
하나는 func로 if(k==n)이 되면 즉, 하나의 경우의 수를 찾으면 cnt++을 하고 return 한다.

그리고 0부터 N-1까지 arr[k]=i를 넣고 if(is_promising(k))를 확인하고 func(k+1)을 한다.

is_promising(int k)에서는 열과 대각선을 체크한다. 행은 func함수에서 체크한다.
if(arr[i] = arr[k]) 로 열을 체크한다
if(abs(k-i) == abs(arr[k]-arr[i]))으로 대각선을 체크한다. 

main에서 cnt를 출력하면 끝이다
