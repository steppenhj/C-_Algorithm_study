#include <iostream>
#include <algorithm>
#include <vector>
//           g++ -o main.exe main.cpp
//           .\main.exe
//    g++ -O2 -Wall -std=c++17 -o main main.cpp
//      ./main

using namespace std;

struct Node{
    char left;
    char right;
};

Node tree[27];

void preorder(char root){
    if (root == '.') return;

    cout << root;
    preorder(tree[root - 'A'].left);
    preorder(tree[root - 'A'].right);
}

void inorder(char root){
    if (root == '.') return;

    inorder(tree[root - 'A'].left);
    cout << root;
    inorder(tree[root - 'A'].right);
}

void postorder(char root){
    if (root == '.') return;

    postorder(tree[root - 'A'].left);
    postorder(tree[root - 'A'].right);
    cout << root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    
    char root, l, r;
    for(int i=0; i<N; i++){
        cin >> root >> l >> r;

        tree[root - 'A'].left = l;
        tree[root - 'A'].right = r;
    }

    preorder('A');
    cout << "\n";

    inorder('A');
    cout << '\n';

    postorder('A');
    cout << '\n';

    return 0;
}
