class Solution {
public:
    int ans=0;
    pair<int,int> dfs(TreeNode* root){
        if(!root) return {0,0};
        auto [ls1,ls2] = dfs(root->left);
        auto [rs1,rs2] = dfs(root->right);
        int sum = ls1+rs1+root->val;
        int c=ls2+rs2+1;
        if(sum/c == root->val) ans++;
        return {sum,c};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};