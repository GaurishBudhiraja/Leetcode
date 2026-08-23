class Solution {
public:
    bool isPalindromic(string s) {
        string res;
        for(char c : s){
            int x = c;
            res += bitset<8>(x).to_string();
        }

        int l=0,r=res.size()-1;
        while(l<r){
            if(res[l]!=res[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};