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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        int carry=0;
        ListNode* temp=dummy;
        while(l1 || l2){
            int t=carry;
            if(l1 && l2){
                t+=l1->val+l2->val;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1){
                t+=l1->val;
                l1=l1->next;
                
            }
            else{
                t+=l2->val;
                l2=l2->next;
            }
            if(t>9) {
                carry=t/10;
                t%=10;}
            else carry=0;
            ListNode* n=new ListNode(t);
            dummy->next=n;
            dummy=dummy->next;
        }
        if(carry){
            ListNode* n=new ListNode(carry);
            dummy->next=n;
        }
        return temp->next;
    }
};