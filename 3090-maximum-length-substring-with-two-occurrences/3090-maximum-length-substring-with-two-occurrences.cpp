class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0,j=0,mx=0;
        unordered_map<char,int> mp;
        while(i<s.size()){
            mp[s[i]]++;
            while(mp[s[i]]>2){
                mp[s[j]]--;
                j++;
            }
            mx = max(mx,i-j+1);
            i++;
        }
        return mx;
    }
};