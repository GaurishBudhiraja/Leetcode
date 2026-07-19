class Solution {
public:
    int longestPalindrome(const std::string& s) {
        unordered_set<char> cs;
        int len=0;
        for(char c:s){
            if(cs.find(c) != cs.end()){
                cs.erase(c);
                len+=2;
            }else{
                cs.insert(c);
            }
        }
        if (!cs.empty()) {
            len+=1;
        }
        return len;
    }
};
