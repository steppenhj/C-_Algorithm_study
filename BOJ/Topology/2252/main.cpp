#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, a, b;
    cin >> N >> M;

    vector<int> adj[N+1];
    int indegree[N+1];
    queue<int> q;
    vector<int> result;

    for(int i=1; i<=N; i++){
        indegree[i] = 0;
    }

    for(int i=0; i<M; i++){
        cin >> a >> b;

        adj[a].push_back(b);

        indegree[b]++;
    }

    for(int i=1; i<=N; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        result.push_back(cur);

        for(int next : adj[cur]){
            indegree[next]--;

            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }

    for(int node : result){
        cout << node << " ";
    }
 
    return 0;
}
