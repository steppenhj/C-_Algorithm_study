토마토 문제 아까는 2D였고 3D로 바뀐 것 하나 뿐이다.
그것 밖에 없다.

방향이 2개 늘어서 6개.
    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};
이것 말고 바뀐 것은 하나이다. 

중요 %%%
기존에는 queue<pair<int, int, int>> q를 사용했다. 하지만, 3D가 되었다.
queue<tuple<int, int, int>> q;를 사용했다.
int x = q.first;  , int y = q.second를 사용했지만
이제는 
int x = get<0>(cur);
int y = get<1>(cur);
int z = get<2>(cur); 을 사용했다!


이 문제도 
#include <cstring>을 사용해서 memset(dist, -1, sizeof(dist))를 적용함
