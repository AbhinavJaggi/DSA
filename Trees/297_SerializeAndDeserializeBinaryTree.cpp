class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*> q;
        string s="";
        q.push(root);
        while(!q.empty()){
            TreeNode* x=q.front();
            q.pop();
            if(x==nullptr) s.append("#,");
            else s.append(to_string(x->val)+',');
            if(x!=nullptr){
                q.push(x->left);
                q.push(x->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root= new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* x=q.front();
            q.pop();
            // connecting left node
            getline(s,str,',');
            if(str=="#") x->left=nullptr;
            else{
                TreeNode* y=new TreeNode(stoi(str));
                x->left=y;
                q.push(y);
            }
            // connecting right node
            getline(s,str,',');
            if(str=="#") x->right=nullptr;
            else{
                TreeNode* y=new TreeNode(stoi(str));
                x->right=y;
                q.push(y);
            }
        }
        return root;
    }
};