class Solution {
public:
    bool F(vector<int> piles,int h,int k) {
        long long hours=0;
        for(int pile : piles) {
            hours+=pile/k;
            if(pile%k != 0) hours++;
            if(hours>h) return false;
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size(),l=1,r=piles[n-1],ans = r;
        while(l<=r){
            int mid=l + (r-l)/2;
            if(F(piles,h,mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};

// F() check karta hai ki agar speed = k ho
// to Koko h hours ke andar finish kar sakti hai ya nahi

// hours = har pile ko finish karne me lagne wale total hours

// Agar speed kaam karti hai
// to aur choti speed try karo (r = mid-1)

// Agar speed kaam nahi karti
// to speed badhao (l = mid+1)

// Binary Search on Answer
// Search space = eating speed (1 se max pile tak)