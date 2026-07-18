class Solution {
    void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent_mpp){
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* x=q.front();
            q.pop();
            if(x->left){
                parent_mpp[x->left]=x;
                q.push(x->left);
            }
            if(x->right){
                parent_mpp[x->right]=x;
                q.push(x->right);
            }
        }
    }
    void rootOfStart(TreeNode* root,int start,TreeNode*& y){
        if(y) return;
        if(root==nullptr) return;
        if(root->val==start) y=root;
        rootOfStart(root->left,start,y);
        rootOfStart(root->right,start,y);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent_mpp;
        parent(root,parent_mpp);
        TreeNode* y=nullptr;
        rootOfStart(root,start,y);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;
        q.push(y);
        visited[y]=true;
        int count=-1;
        while(!q.empty()){
            int n=q.size();
            count++;
            for(int i=0;i<n;i++){
            TreeNode* x=q.front();
            q.pop();
            if(x->left && !visited[x->left]){
                q.push(x->left);
                visited[x->left]=true;
            }
            if(x->right && !visited[x->right]){
                q.push(x->right);
                visited[x->right]=true;
            }
            if(parent_mpp.count(x) && !visited[parent_mpp[x]]){
                q.push(parent_mpp[x]);
                visited[parent_mpp[x]]=true;
            }
            }
        }
    return count;  
    }
};