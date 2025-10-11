#include <iostream>
#include <queue>
#include <vector>

//           g++ -o main.exe main.cpp
//           .\main.exe

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int m;
        cin >> m;

        vector<int> ans;
        priority_queue<int, vector<int>> maxheap;
        priority_queue<int, vector<int>, greater<int>> minheap;

        for(int i=1; i<=m; i++){
            int x;
            cin >> x;

            if(maxheap.size() == minheap.size()) maxheap.push(x);
            else minheap.push(x);

            if(!maxheap.empty() && !minheap.empty() && (maxheap.top() > minheap.top())){
                int maxTop = maxheap.top();
                maxheap.pop();
                int minTop = minheap.top();
                minheap.pop();

                maxheap.push(minTop);
                minheap.push(maxTop);
            }

            if(i % 2){
                ans.push_back(maxheap.top());
            }
        }

        cout << ans.size() << '\n';
        for(int i=0; i<ans.size(); i++){
            if(i>0 && i%10==0) cout << '\n';
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
