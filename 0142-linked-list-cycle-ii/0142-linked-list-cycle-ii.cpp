class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* s=head;
        ListNode* f=head;
        while(f&&f->next){
            s=s->next;
            f=f->next->next;
            if(s==f) break;
        }
        if(!f||!f->next) return nullptr;
        f=head;
        while(f!=s){
            f=f->next;
            s=s->next;
        }
        return s;
    }
};