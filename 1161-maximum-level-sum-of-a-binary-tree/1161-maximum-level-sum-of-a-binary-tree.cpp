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
    vector<int> sum={INT_MIN};
    void hehe(TreeNode* root, int l=1){
        if(root==nullptr) return;
        if(sum.size()==l)sum.push_back(root->val);
        else sum[l]+=root->val;
        hehe(root->left,l+1);
        hehe(root->right,l+1);
    }
    int maxLevelSum(TreeNode* root){
        hehe(root);
        return max_element(sum.begin(),sum.end())-sum.begin();

    }
};