2차원에 dx, dy가 이동하는 방향이 8개가 된 것 뿐이다. 
똑같이 bfs를 만들어서 풀면 된다

queue<pair<int, int>> q;를 사용하고 첫 번째 startPos를 먼저 넣어줌
while문 만들어서 bfs 함수 완성하면 됨.

main함수에선 T써서 케이스 개수 받아야 함.
이것 때문에 
#include <cstring>을 호출해야 하고, 
memset(dist, -1, sizeof(dist)); 를 bfs() 호출 전에 해야함.
