#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int count_nodes(int start, int n, vector<vector<int>> &adj){
    vector<bool> visited(n+1, false);
    queue<int> q;
    //여기는 그냥 그래프의 노드 수를 세어주는 함수 생성.
    q.push(start);
    visited[start] = true;
    int cnt = 1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int next : adj[cur]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 20000;
    
    vector<vector<int>> adj(n+1);
    for(auto w : wires){
        adj[w[0]].push_back(w[1]);
        adj[w[1]].push_back(w[0]);
    }
    
    for(auto w : wires){
        int v1 = w[0];
        int v2 = w[1];
        
        for(int i=0; i<adj[v1].size(); i++){
            if(adj[v1][i] == v2){
                adj[v1].erase(adj[v1].begin() + i);
                break;
            }
        }
        
        for(int i=0; i<adj[v2].size(); i++){
            if(adj[v2][i] == v1){
                adj[v2].erase(adj[v2].begin() + i);
                break;
            }
        }
        
        int left_cnt = count_nodes(v1, n, adj);
        int right_cnt = n - left_cnt;
        
        int gap = abs(left_cnt - right_cnt);
        answer = min(answer, gap);
        
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    
    return answer;
}
