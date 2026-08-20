class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int row = q.front().first;
            int col= q.front().second;
            q.pop();
            for(int nrow=-1;nrow<=1;nrow++){
                for(int ncol=-1;ncol<=1;ncol++){
                    int rrow=row+nrow;
                    int ccol=col+ncol;
                    if((nrow==0 || ncol==0) && rrow>=0 && rrow<n && ccol>=0 && ccol<m && grid[rrow][ccol]=='1' && !vis[rrow][ccol]){
                        q.push({rrow,ccol});
                        vis[rrow][ccol]=1;
                    }
                
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]=='1' && !vis[row][col]){
                    bfs(row,col,vis,grid);
                    count++;
                }
            }
        }
    return count;
    }
};