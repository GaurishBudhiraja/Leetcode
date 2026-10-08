class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int c=0;
        if(s=="") return "";
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' && c++ > 0) res+= s[i];
            if(s[i] == ')' && c-- > 1) res+= s[i];
        }
        return res;
    }
};