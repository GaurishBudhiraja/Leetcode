class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n=arr.size(),i=0,j=1;
        vector<int>res(n);
        for(int k=0;k<n;k++){
            if(arr[k]>0){
                res[i]=arr[k];
                i+=2;
            }
            else{
                res[j]=arr[k];
                j+=2;
            }
        }
        return res;
    }
};