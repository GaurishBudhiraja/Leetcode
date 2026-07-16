class Solution {
public:
    static bool cmp(string a,string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums){
        vector<string> v;
        for(int num : nums){
            v.push_back(to_string(num));
        }
        sort(v.begin(),v.end(),cmp);
        if(v[0] == "0"){
            return "0";
        }
        string res = "";
        for(string s : v){
            res += s;
        }
        return res;
    }
};