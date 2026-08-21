class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> innode(V);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                innode[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(innode[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                innode[it]--;
                if(innode[it]==0) q.push(it);
            }
        }
        if(cnt==V) return true;
        return false;

    }
};