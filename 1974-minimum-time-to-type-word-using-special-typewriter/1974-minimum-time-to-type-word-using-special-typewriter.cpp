class Solution {
public:
    int minTimeToType(string word) {
        int c=word.size(),p='a';
        for(auto ch : word){
            c+=min(abs(ch-p),26-abs(p-ch));
            p=ch;
        }
        return c;
    }
};