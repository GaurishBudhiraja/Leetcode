class Solution {
public:
    bool isValidBST(TreeNode* root){
        return v(root,LONG_MIN,LONG_MAX);
    }
    bool v(TreeNode* root,long mn,long mx){
        if(!root) return true;
        if(!(root->val>mn && root->val<mx)) return false;
        return v(root->left,mn,root->val) && v(root->right,root->val,mx);
    }
};

