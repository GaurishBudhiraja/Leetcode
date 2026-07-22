class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int n=1;
        ListNode* v1 = head;
        while(v1->next){
            v1 = v1->next;
            n++;
        }
        k %=n;
        if(k==0) return head;

        ListNode* cur = head;
        for (int i=0;i<n-k-1;i++) {
            cur = cur->next;
        }
        ListNode* newHead = cur->next;
        v1->next = head;
        cur->next = nullptr;
        return newHead;

    }
};