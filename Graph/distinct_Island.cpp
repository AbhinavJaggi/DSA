class Solution {
    void DFS(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid,vector<pair<int,int>>& vec,int baserow,int basecol){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        vec.push_back({row-baserow,col-basecol});
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int rrow=row+dr[i];
            int ccol=col+dc[i];
            if(rrow>=0 && rrow<n && ccol>=0 && ccol<m && !vis[rrow][ccol] && grid[rrow][ccol]=='L'){
                DFS(rrow,ccol,vis,grid,vec,baserow,basecol);
            }
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<char>>& grid) {
        // code here
        set<vector<pair<int,int>>> s;
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>> vec;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L' && !vis[i][j]){
                    DFS(i,j,vis,grid,vec,i,j);
                    s.insert(vec);
                    vec.clear();
                }
            }
        }
        return s.size();
    }
};
