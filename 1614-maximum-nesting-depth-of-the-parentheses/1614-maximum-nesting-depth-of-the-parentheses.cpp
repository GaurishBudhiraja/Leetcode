class Solution {
public:
    int maxDepth(string s) {
        int c=0,dep=0;
        for(int i=0;i<s.size();i++){
            dep+=(s[i]=='(')-(s[i]==')');
            c=max(c,dep);
        }
        return c;
    }
};