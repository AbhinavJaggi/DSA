class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;
        pq.push({0,k}); // dis,node
        while(!pq.empty()){
            int wt =pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int AdjNode=it.first;
                int weightAdjNode=it.second;
                if(wt+weightAdjNode<dis[AdjNode]){
                    dis[AdjNode]=wt+weightAdjNode;
                    pq.push({dis[AdjNode],AdjNode});
                }
            }
        }
        int ans=*max_element(dis.begin()+1,dis.end());
        if(ans==INT_MAX) return -1;
        return ans;
    }
};