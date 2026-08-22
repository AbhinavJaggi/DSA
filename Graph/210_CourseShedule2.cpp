class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        for(int i=0;i<prerequisites.size();i++ ){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        vector<int> innode(V);
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                innode[it]++;
            }
        }
        for(int i=0;i<V;i++){
            if(innode[i]==0) q.push(i);
        }
        int count = 0;
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto it:adj[node]){
                innode[it]--;
                if(innode[it]==0) q.push(it);
            }
            ans.push_back(node);
        }
        if(count!=V) return {};
        return ans;
    }
};