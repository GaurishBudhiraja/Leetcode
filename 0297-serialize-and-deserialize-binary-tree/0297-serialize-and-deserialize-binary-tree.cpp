class Codec {
public:
    string serialize(TreeNode* root) {
        vector<string> res;
        function<void(TreeNode*)> dfs = [&](TreeNode* node){
            if(!node){
                res.push_back("N");
                return;
            }
            res.push_back(to_string(node->val));
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        string ans;
        for(int i=0;i<res.size();i++){
            if(i) ans += ",";
            ans += res[i];
        }
        return ans;
    }
    TreeNode* deserialize(string data) {
        vector<string> vals;
        stringstream ss(data);
        string x;
        while(getline(ss,x,','))
            vals.push_back(x);
        int i = 0;
        function<TreeNode*()> dfs = [&]() -> TreeNode* {
            if(vals[i] == "N"){
                i++;
                return nullptr;
            }
            TreeNode* node = new TreeNode(stoi(vals[i]));
            i++;
            node->left = dfs();
            node->right = dfs();
            return node;
        };
        return dfs();
    }
};