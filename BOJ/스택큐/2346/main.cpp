#include <iostream>
#include <deque>

//           g++ -o main.exe main.cpp
//           .\main.exe

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int x;
    deque<pair<int, int>> dq;

    for(int i=0; i<N; i++){
        cin >> x;
        dq.push_back(make_pair(x, i+1)); 
    }
    while(!dq.empty()){
        int current_value = dq.front().first;
        cout << dq.front().second << " ";
        dq.pop_front();

        if(dq.empty()) break;

        if(current_value > 0){
            for(int i=0; i<current_value-1; i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } 
        else{
            for(int i=0; i< (-1)*current_value; i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    return 0;
}
