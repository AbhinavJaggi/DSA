class DisjointSet{
public:
    vector<int> parent,ssize,rank;
    DisjointSet(int n){
        parent.resize(n+1);
        ssize.resize(n+1,1);
        rank.resize(n+1,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int ultimate_parent(int node){
        if(node==parent[node]) return node;
        return parent[node]=ultimate_parent(parent[node]);
    }
    void UnionBySize(int u,int v){
        int ul_u=ultimate_parent(u);
        int ul_v=ultimate_parent(v);
        if(ul_u==ul_v) return;
        if(ssize[ul_u]<ssize[ul_v]){
            parent[ul_u]=ul_v;
            ssize[ul_v]+=ssize[ul_u];
        }
        else{
            parent[ul_v]=ul_u;
            ssize[ul_u]+=ssize[ul_v];
        }
    }
    void UnionByRank(int u,int v){
        int ul_u=ultimate_parent(u);
        int ul_v=ultimate_parent(v);
        if(ul_u==ul_v) return;
        if(rank[ul_u]<rank[ul_v]){
            parent[ul_u]=ul_v;
        }
        else if(rank[ul_v]<rank[ul_u]){
            parent[ul_v]=ul_u;
        }
        else{
            parent[ul_v]=ul_u;
            rank[ul_u]++;
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        // connecting nodes
        int n=grid.size();
        int m=grid[0].size();
        DisjointSet ds(n*m);
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        // step 1 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    int rrow=i+dr[k];
                    int ccol=j+dc[k];
                    if(rrow>=0 && rrow<n && ccol<m && ccol>=0 && grid[i][j]==1 && grid[rrow][ccol]==1 && ds.ultimate_parent(i*m+j)!=ds.ultimate_parent(rrow*m+ccol)){
                        ds.UnionBySize(i*m+j,rrow*m+ccol);
                    }
                }
            }
        }
        // step 2
        unordered_set<int> st;
        int ans=0;
        int ssum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    for(int k=0;k<4;k++){
                        int rrow=i+dr[k];
                        int ccol=j+dc[k];
                        if(rrow>=0 && rrow<n && ccol>=0 && ccol<m && grid[rrow][ccol]==1){
                            st.insert(ds.ultimate_parent(rrow*m+ccol));
                        }
                    }
                    ssum=0;
                    while(!st.empty()){
                        int node=*st.begin();
                        st.erase(node);
                        ssum+=ds.ssize[node];
                    }
                    ans=max(ans,ssum+1);
                }
            }
        }
        for(int i=0;i<n*m;i++){
            ans=max(ans,ds.ssize[ds.ultimate_parent(i)]);
        }
        return ans;
    }
};