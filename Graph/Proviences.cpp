class Solution {
    void dfs(int node,vector<int> &vis,vector<vector<int>>& isConnected){
        vis[node]=1;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i]==1 && !vis[i]){
                dfs(i,vis,isConnected);
            }
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(),0);
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,isConnected);
            }
        }
        return count;
    }
};