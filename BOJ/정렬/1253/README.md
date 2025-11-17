범위가 크니깐 vector<long> arr(n);으로 선언한다.

for문에서 arr[i]를 target으로 잡고, left=0, right=n-1으로 선언한다.
while문을 for문 안에서 해서, O(n^2)으로 한다고 보면 된다. 
if(left==i){ left++; continue; },
if(right==i) {right--; continue; }으로 left, right가 i가 되는 걸 막는다. 
그 이후로는 long sum = arr[left] + arr[right]로 하면 된다. 이건 내가 아는 것..

핵심은 어떻게든 O(n^2)가 되도록 for 하나, while 하나만 사용한 것.
