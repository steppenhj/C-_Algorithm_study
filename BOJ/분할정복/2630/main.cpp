#include <iostream>


//           g++ -o main.exe main.cpp
//           .\main.exe

using namespace std;

int arr[129][129];
int white = 0;
int blue = 0;

void slice(int x, int y, int n){
    bool cut = false;
    int first_color = arr[x][y];
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(arr[i][j] != first_color){
                cut = true;
                break;
            }
        }
    }

    if(cut){
        slice(x, y, n/2);
        slice(x, y+n/2, n/2);
        slice(x+n/2, y, n/2);
        slice(x+n/2, y+n/2, n/2);
    } else{
        if(first_color == 1) blue++;
        else white++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    slice(0, 0, n);
    cout << white << '\n';
    cout << blue << '\n';
    
    return 0;
}
