class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int res=0;
        dfs(root,true,0,res); 
        dfs(root,false,0,res);
        return res;
    }
private:
    void dfs(TreeNode* root,bool l,int len,int &res){
        if (!root) return;
        res=max(res,len);
        if(l){
            dfs(root->left,false,len+1,res);
            dfs(root->right,true,1,res);
        }else{
            dfs(root->right,true,len+1,res);
            dfs(root->left,false,1,res);
        }
    }
};