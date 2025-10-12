#include <iostream>
#include <string>

using namespace std;

string arr[64];

void solve(int x, int y, int size){
    char curr = arr[x][y];
    
    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(arr[i][j] != curr){
                cout << '(';
                solve(x, y, size/2);
                solve(x, y+size/2, size/2);
                solve(x+size/2, y, size/2);
                solve(x+size/2, y+size/2, size/2);
                cout << ')';
                return;
            }
        }
    }
    cout << curr;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    solve(0, 0, n);
    
    return 0;
}
