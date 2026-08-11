class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int> vis_arr(adj.size(),0);
        vis_arr[0]=1;
        queue<int> q;
        q.push(0);
        vector<int> vec;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vec.push_back(node);
            for(auto it : adj[node]){
                if(!vis_arr[it]){
                    q.push(it);
                    vis_arr[it]=1;
                }
            }
        }
        return vec;
    }
};