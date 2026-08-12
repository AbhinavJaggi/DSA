class Solution {
  private:
    void depth(int node,vector<int>& vis,vector<vector<int>>& adj,vector<int> & vec){
        vis[node]=1;
        vec.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                depth(it,vis,adj,vec);
            }
        }
        return;
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> vis(adj.size(),0);
        vector<int> vec;
        int start=0;
        depth(start,vis,adj,vec);
        return vec;
    }
};
