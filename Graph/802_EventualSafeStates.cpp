class Solution {
    bool DFS(int node,vector<int>& vis,vector<int>& path,vector<int>& check,vector<vector<int>>& graph){
        vis[node]=1;
        path[node]=1;

        for(auto it:graph[node]){
            if(!vis[it]){
                if(DFS(it,vis,path,check,graph)==true) return true;
            }
            else if(path[it]){
                return true;
            }
        }
        check[node]=1;
        path[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> path(n,0);
        vector<int> check(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                DFS(i,vis,path,check,graph);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]) ans.push_back(i);
        }
        return ans;
    }
};