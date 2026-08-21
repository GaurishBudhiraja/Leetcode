class Solution {
public:
    bool isValidBST(TreeNode* root) {

        return v(root,LONG_MIN,LONG_MAX);

    }

    bool v(TreeNode* node,long mn,long mx){

        if(!node) return true;

        if(!(node->val>mn && node->val<mx)) return false;

        return v(node->left,mn,node->val) && v(node->right,node->val,mx);

    }

};

