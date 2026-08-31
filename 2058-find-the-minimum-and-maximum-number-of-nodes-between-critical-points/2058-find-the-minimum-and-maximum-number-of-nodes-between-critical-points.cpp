class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i=1,mn=INT_MAX,first=-1,last=-1;
        ListNode *prev=head,*cur=head->next;
        while(cur->next){
            if((cur->val>prev->val && cur->val>cur->next->val) ||
               (cur->val<prev->val && cur->val<cur->next->val)){
                
                if(first==-1) first=i;
                else mn=min(mn,i-last);
                last=i;
            }
            prev=cur;
            cur=cur->next;
            i++;
        }
        if(first==-1 || first==last) return {-1,-1};
        return {mn,last-first};
    }
};