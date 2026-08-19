class Solution {
  public:
  // khan's algo
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> innode(V); // ma kiska andr hu
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                innode[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(innode[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                innode[it]--;
                if(innode[it]==0) q.push(it);
            }
        }
        return ans;
    }
};