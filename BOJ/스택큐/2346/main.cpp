#include <iostream>
#include <deque>
#include <cmath>

//           g++ -o main.exe main.cpp
//           .\main.exe

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    deque<pair<int, int>> dq;

    for(int i=0; i<N; i++){
        int paper_value;
        cin >> paper_value;
        dq.push_back({paper_value, i+1});
    }

    while(!dq.empty()){
        int move_value = dq.front().first;
        cout << dq.front().second << " ";
        dq.pop_front();

        if(move_value > 0){
            for(int i=0; i<move_value-1; i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            for(int i=0; i<abs(move_value); i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    return 0;
}
