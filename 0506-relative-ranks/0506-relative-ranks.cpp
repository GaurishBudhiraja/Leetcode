class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        priority_queue<pair<int,int>>pq;
        vector<string> ans(n);
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        int c=0; 
        while(!pq.empty()){
           c++;
           if(c==1){
            ans[pq.top().second]="Gold Medal";
            pq.pop();
           }
           else if(c==2){
            ans[pq.top().second]="Silver Medal";
            pq.pop();
           }
           else if(c==3){
            ans[pq.top().second]="Bronze Medal";
            pq.pop();
           }
           else{
            ans[pq.top().second]=to_string(c);
            pq.pop(); 
           }
        }
        return ans;
    }
};