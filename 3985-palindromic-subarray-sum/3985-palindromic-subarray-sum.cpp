//Not done by me copied pasted this one will do later

class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }
        long long ans = 0;
        // Odd length palindromes
        vector<int> d1(n);
        for(int i = 0, l = 0, r = -1; i < n; i++){

            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);

            while(i - k >= 0 && i + k < n &&
                  nums[i - k] == nums[i + k]){
                k++;
            }

            d1[i] = k;

            int left = i - k + 1;
            int right = i + k - 1;

            long long sum = prefix[right + 1] - prefix[left];

            ans = max(ans, sum);

            if(right > r){
                l = left;
                r = right;
            }
        }

        // Even length palindromes
        vector<int> d2(n);

        for(int i = 0, l = 0, r = -1; i < n; i++){

            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);

            while(i - k - 1 >= 0 && i + k < n &&
                  nums[i - k - 1] == nums[i + k]){
                k++;
            }

            d2[i] = k;

            if(k > 0){
                int left = i - k;
                int right = i + k - 1;

                long long sum = prefix[right + 1] - prefix[left];

                ans = max(ans, sum);
            }

            if(i + k - 1 > r){
                l = i - k;
                r = i + k - 1;
            }
        }

        return ans;
    }
};