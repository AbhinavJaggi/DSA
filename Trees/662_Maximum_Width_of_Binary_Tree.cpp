class Solution {
    void width(TreeNode* root,long long& maxi){
        long long first,last;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            long long mn=q.front().second;
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                TreeNode* x=it.first;
                long long y=it.second;
                long long curr=y-mn;
                if(i==0) first=curr;
                if(i==n-1) last=curr;
                if(x->left) q.push({x->left,(long long)2*curr});
                if(x->right) q.push({x->right,(long long)2*curr+1});
            }
            maxi=max(maxi,last-first+1);
        }
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long maxi=INT_MIN;
        width(root,maxi);
        return maxi;
    }
};