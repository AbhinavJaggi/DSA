class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;// maxw,{row,col}
        int n=grid.size();
        vector<vector<int>> water(n,vector<int>(n,INT_MAX));
        water[0][0]=grid[0][0];
        pq.push({water[0][0],{0,0}});
        while(!pq.empty()){
            int maxw=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==n-1) return maxw;
            int dr[]={1,0,-1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int rrow=row+dr[i];
                int ccol=col+dc[i];
                if(rrow>=0 && rrow<n && ccol>=0 && ccol<n){
                    int newWater = max(maxw, grid[rrow][ccol]);
                    if(newWater<water[rrow][ccol]){
                        water[rrow][ccol]=newWater;
                        pq.push({water[rrow][ccol],{rrow,ccol}});
                    }
                }
            }
        }
        return -1;
    }
};