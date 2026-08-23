bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        // vector<vector<int>> adj(V);
        // vector<int> vis(V);
        // vector<int> pathVis(V);
        // for(int i=0;i<edges.size();i++){
        //     adj[edges[i][0]].push_back(edges[i][1]);
        // }
        // for(int i=0;i<V;i++){
        //     if(!vis[i]){
        //         if(DFS(i,vis,pathVis,adj)==true) return true;
        //     }
        // }
        // return false;
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> innode(V);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                innode[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(innode[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                innode[it]--;
                if(innode[it]==0) q.push(it);
            }
        }
        if(cnt==V) return false;
        return true;
    }
};