class Solution {
private:
    int poi=0;
    unordered_map<int,int> mp;
    TreeNode* build(vector<int>& po,int s,int e){
        if(s>e) return nullptr;
        int rootVal = po[poi++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];

        root->left = build(po,s,mid-1);
        root->right = build(po,mid+1,e);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& po, vector<int>& io) {
        if(po.empty() && io.empty()) return nullptr;
        for(int i=0;i<io.size();i++){
            mp[io[i]]=i;
        }
        return build(po,0,io.size()-1);
    }

};