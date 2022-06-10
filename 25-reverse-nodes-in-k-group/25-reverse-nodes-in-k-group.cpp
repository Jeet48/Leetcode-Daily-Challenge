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
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* revList = NULL;
        while(head != tail) {
            ListNode* temp = head;
            head = head->next;
            temp->next = revList;
            revList = temp;
        }
        return revList;
    }
    
    int length(ListNode* head) {
        int count = 0;
        while(head) {
            head = head->next;
            count++;
        }
        return count;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int iterations = length(head) / k;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* ptr = head;   
        ListNode* prev = dummy;
        while(iterations--) {
            ListNode* tail = ptr;
            int count = 1;
            while(count < k) {
                tail = tail->next;
                count++;
            }
            
            ListNode* nextNodes = tail->next;
            prev->next = reverse(ptr, tail->next);
            
            while(prev->next != NULL) {
                prev = prev->next;
            }
            prev->next = nextNodes;
            ptr = nextNodes;
        }
        
        return dummy->next;
    }
}; 