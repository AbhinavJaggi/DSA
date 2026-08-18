class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        bool a=false;
        queue<pair<int,int>> q;
        vector<vector<int>> copy=grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                int drow[]={-1,0,1,0};
                int dcol[]={0,-1,0,1};
                for(int i=0;i<4;i++){
                    int rrow=row+drow[i];
                    int ccol=col+dcol[i];
                    if(rrow>=0 && rrow<n && ccol>=0 && ccol<m && grid[rrow][ccol]==1 && copy[rrow][ccol]!=2 ){
                        q.push({rrow,ccol});
                        copy[rrow][ccol]=2;
                        a=true;
                    }
                }
            }
            if(a){
                count++;
                a=false;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(copy[i][j]==1) return -1;
            }
        }
        return count;
    }
};