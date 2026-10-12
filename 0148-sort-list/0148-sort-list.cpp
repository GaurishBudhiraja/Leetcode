class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        vector<int> v;
        ListNode* curr=head;
        while(curr!=nullptr){
            v.push_back(curr->val);
            curr=curr->next;
        }
        sort(v.begin(),v.end());
        curr=head;
        int i=0;
        while(curr != nullptr){
            curr->val=v[i];
            i++;
            curr=curr->next;
        }
        return head;
    }
};