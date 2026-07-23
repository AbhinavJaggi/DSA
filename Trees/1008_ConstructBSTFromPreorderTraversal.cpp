class Solution {
    TreeNode* BST(vector<int>& preorder,int upperBound,int& i){
        if(i==preorder.size() || preorder[i]>upperBound ) return NULL;
        TreeNode* root=new TreeNode(preorder[i]);
        i++;
        root->left=BST(preorder,root->val,i);
        root->right=BST(preorder,upperBound,i);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        TreeNode* ans= BST(preorder,INT_MAX,i);
        return ans;
    }
};