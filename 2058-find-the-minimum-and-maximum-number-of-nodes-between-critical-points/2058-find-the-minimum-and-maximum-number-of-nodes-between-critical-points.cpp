class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i=1,mn=INT_MAX,f=-1,l=-1;
        ListNode *prev=head,*cur=head->next;
        while(cur->next){
            if((cur->val>prev->val && cur->val>cur->next->val) ||
               (cur->val<prev->val && cur->val<cur->next->val)){
                
                if(f==-1) f=i;
                else mn=min(mn,i-l);
                l=i;
            }
            prev=cur;
            cur=cur->next;
            i++;
        }
        if(f==-1 || f==l) return {-1,-1};
        return {mn,l-f};
    }
};