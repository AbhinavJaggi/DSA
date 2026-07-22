class Solution {
    void mirror(TreeNode* left,TreeNode* right ,bool& a){
        if(a==false) return;
        if(left==nullptr && right==nullptr) return;
        if(left==nullptr && right!=nullptr){
            a=false;
            return;
        }
        if(left!=nullptr && right==nullptr){
            a=false;
            return;
        }
        if(left->val!=right->val){
            a=false;
            return;
        }
        mirror(left->left,right->right,a);
        mirror(left->right,right->left,a);
    }
public:
    bool isSymmetric(TreeNode* root) {
        bool a=true;
        mirror(root->left,root->right,a);
        return a;
    }
};