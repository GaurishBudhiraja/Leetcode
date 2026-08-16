/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return nod(root,root->val);
    }
    int nod(TreeNode* root,int mx){
        if(!root) return 0;
        int c=0;
        if(root->val >= mx) c=1;
        mx = max(mx,root->val);
        c+=nod(root->left,mx);
        c+=nod(root->right,mx);
        return c;
    }
};