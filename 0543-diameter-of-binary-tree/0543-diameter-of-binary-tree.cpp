class Solution {
public:
    int d=0;
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return d;
    }
    int height(TreeNode* root){
        if(!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        d = max(d,l+r);
        return 1 + max(l,r);
    }
};