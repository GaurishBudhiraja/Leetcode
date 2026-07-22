/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int res=INT_MIN,n=1;
        ListNode* v1 = head;
        while(v1->next){
            v1=v1->next;
            n++;
        }
        ListNode* v2 = head;
        vector<int> resu;
        for(int i=0;i<n;i++){
            resu.push_back(v2->val);
            v2=v2->next;
        }
        for(int i=0;i<n/2;i++){
            int sum = resu[i] + resu[n-i-1];
            res = max(res,sum);
        }
        return res;
    }
};