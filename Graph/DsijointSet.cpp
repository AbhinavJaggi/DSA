#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> parent,ssize,rank;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        ssize.resize(n+1,1);
        rank.resize(n+1,1);
        for(int i=1;i<=n;i++){
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
int main(){
    DisjointSet ds(7);
    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);
    if(ds.ultimate_parent(3)==ds.ultimate_parent(7)){
        cout << "yes";
    }
    else{
        cout << "no";
    }
    cout << endl;
    ds.UnionBySize(3,7);
    if(ds.ultimate_parent(3)==ds.ultimate_parent(7)){
        cout << "yes";
    }
    else{
        cout << "no";
    }
    return 0;
}