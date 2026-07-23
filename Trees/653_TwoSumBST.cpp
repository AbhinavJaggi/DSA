class BSTiterator{
    stack<TreeNode*> st;
    bool a =true;
    public:
    BSTiterator(TreeNode* root,bool value){
        a=value;
        pushelement(root,a);
    }
    int next(){
        TreeNode* x=st.top();
        st.pop();
        int returningValue=x->val;
        if(a==true) x=x->right;
        else x=x->left;
        pushelement(x,a);
        return returningValue;
    }
    bool hasNext(){
        return !st.empty();
    }
    private:
    void pushelement(TreeNode* root,bool a){
        while(root){
            st.push(root);
            if(a==true) root=root->left;
            else root=root->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTiterator l(root,true);
        BSTiterator r(root,false);
        int i=l.next();
        int j=r.next();
        while(i<j){
        if(i+j==k) return true;
        else if(i+j<k) i=l.next();
        else j=r.next();
        }
        return false;
    }
};