알고리즘 자체는 쉽다. 전위, 중위, 후위 이건 이미 배운거고 동작도 같은데 cpp로 하려고 하니깐 자료구조만 좀 습득하면 되겠다.

struct Node{char left; char right;};로 구조체는 쓰는 것. 오랜만이다.

Node tree[27]; 선언해주고

preorder, inorder, postorder 코드 자체는 특별할 건 없다.

문제 특성상 알파벳 트리라서 root - 'A'를 꾸준히 해야 한다. 그리고, 구조체를 사용했는데 특이하게 tree[root - 'A'].left = l;  이렇게 .left, .right를 사용한다.
