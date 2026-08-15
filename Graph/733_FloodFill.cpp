class Solution {
    void bfs(int sr,int sc,int oldColor,int color,vector<vector<int>> & image){
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            image[row][col]=color;

            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            for( int i =0;i<4;i++){
                int rrow=row+dr[i];
                int ccol=col+dc[i];
                if(rrow>=0 && rrow<n && ccol >=0 && ccol < m && image[rrow][ccol]==oldColor){
                    q.push({rrow,ccol});
                }
            }
        }
        return ;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor=image[sr][sc];
        if(oldColor==color) return image;
        bfs(sr,sc,oldColor,color,image);
        return image;
        
    }
};