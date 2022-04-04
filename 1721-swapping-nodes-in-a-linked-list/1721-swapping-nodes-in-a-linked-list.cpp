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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *l1=head;
        ListNode *l2=head;
        ListNode *curr=head;
        
        int count = 1;
        while(curr!=NULL) {
            if(count<k){
                l1=l1->next;
            }
            if(count>k) {
                l2=l2->next;
            }
            curr=curr->next;
            count++;
        }
        int temp=l1->val;
        l1->val=l2->val;
        l2->val=temp;
        
        return head;
        
    }
};