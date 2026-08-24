class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=1;
        if(grid[0][0]==1) return -1;
        pq.push({1,{0,0}});
        while(!pq.empty()){
            int distance=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1) return distance;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0 && j==0) continue;
                    int rrow=row+i;
                    int ccol=col+j;
                    if(rrow>=0 && rrow<n && ccol>=0 && ccol<m && grid[rrow][ccol]==0 && distance+1<dis[rrow][ccol]){
                        dis[rrow][ccol]=distance+1;
                        pq.push({dis[rrow][ccol],{rrow,ccol}});
                    }
                }
            }
        }
        return -1;
    }
};