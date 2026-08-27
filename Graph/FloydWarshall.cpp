class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,1e4));
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            matrix[u][v]=wt;
            matrix[v][u]=wt;
        }
        for(int i=0;i<n;i++){
            matrix[i][i]=0;
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    int wwt=min(matrix[i][j],matrix[i][via]+matrix[via][j]);
                    matrix[i][j]=wwt;
                }
            }
        }
        vector<int> dis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=distanceThreshold){
                    dis[i]++;
                }
            }
        }
        int min=dis[0];
        int indx=0;
        for(int i=0;i<n;i++){
            if(dis[i]<=min){
                min=dis[i];
                indx=i;
            }
        }
        return indx;
    }
};