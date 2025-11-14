정렬 + Greedy로 풀어야 한다.
정렬은 간단하게 구현하고

int tape_end_pos = -1으로 우선 정의한다.
for문 안에서 int current_leak_pos = position[i]로 해주고
if(current_leak_pos > tape_end_pos){ cnt++ tape_end_pos=current_leak_pos+L-1; }
하면 된다.

즉, 젤 앞에서부터 구멍을 막고, 
테이프 길이 고려해서 마지막 위치인 tape_end_pos = current_leak_pos + L - 1
