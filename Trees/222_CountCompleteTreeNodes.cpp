class Solution {
    int heightR(TreeNode* root){
        int count=0;
        while(root){
            count++;
            root=root->right;
        }
        return count;
    }
    int heightL(TreeNode* root){
        int count=0;
        while(root){
            count++;
            root=root->left;
        }
        return count;
    }
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh=heightL(root);
        int rh=heightR(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);

    }
};