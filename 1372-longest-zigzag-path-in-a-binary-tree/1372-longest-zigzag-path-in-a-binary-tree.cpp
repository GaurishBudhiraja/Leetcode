class Solution {
public:
    int ans=INT_MIN;
    void findLength(TreeNode*root ,int l,int r){
        if(!root) return;
        ans=max(ans,max(l,r));
        findLength(root->left,r+1 ,0);
        findLength(root->right,0,l+1);
    }
    int longestZigZag(TreeNode* root){
        findLength(root,0,0);
        return ans;
    }
};