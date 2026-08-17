class solution{
bool DFS(int node,int color,vector<int>& vis,vector<vector<int>>& graph){
        vis[node]=color;
        for(auto it:graph[node]){
            if(vis[it]==-1){
                if(DFS(it,!color,vis,graph)==false) return false;
            }
            else{
                if(vis[it]==color){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(DFS(i,0,vis,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};