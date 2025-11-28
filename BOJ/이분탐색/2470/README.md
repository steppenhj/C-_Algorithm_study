이건 left=0, right=max_val 이런 느낌이 아니다...
보통 개수의 숫자가 개컸는데 그것도 아니다. 

min_abs = 20억으로 잡는 게 포인트네.

if(abs(sum) < min_abs) 이면 옳게된 거 
min_abs = abs(sum)
ans_left = arr[left], arr_right=arr[right] 박아줌.

이동은 if(sum<0)이면 음수니까 left++
else{ right-- } 해준다.
