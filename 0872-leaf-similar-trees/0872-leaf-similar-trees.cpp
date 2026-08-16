class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1,l2;
        c(root1,l1);
        c(root2,l2);
        return l1==l2;
    }
    void c(TreeNode* root,vector<int>& l){
        if(root==nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            l.push_back(root->val);
        }
        c(root->left,l);
        c(root->right,l);
    }
};