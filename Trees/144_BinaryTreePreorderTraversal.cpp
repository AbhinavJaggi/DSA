class Solution {
    void ans(TreeNode* root,vector<int>& vec){
        if(root==nullptr) return;
        vec.push_back(root->val);
        ans(root->left,vec);
        ans(root->right,vec);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        ans(root,vec);
        return vec;
    }
};