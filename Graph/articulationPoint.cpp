class Solution {
    public:
    int timer=0;
    void DFS(int node,int parent,vector<int>& vis,vector<int>&low,vector<int>&tim,vector<int>&mark,vector<vector<int>>& adj){
        vis[node]=1;
        low[node]=tim[node]=timer;
        timer++;
        int child=0;
        for(auto it:adj[node]){
            if(parent==it) continue;
            if(!vis[it]){
                DFS(it,node,vis,low,tim,mark,adj);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tim[node] && parent!=-1){
                    mark[node]=1;
                }
                child++;
            }
            else{
                    low[node]=min(low[node],tim[it]);
                }
        }
        if(child>1 && parent==-1){
            mark[node]=1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> low(V);
        vector<int> tim(V);
        vector<int> vis(V,0);
        vector<int> mark(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                DFS(i,-1,vis,low,tim,mark,adj);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0) return {-1};
        return ans;
        
    }
};