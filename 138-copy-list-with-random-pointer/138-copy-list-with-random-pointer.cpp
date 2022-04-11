/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


   class Solution {
public:
    Node* copyRandomList(Node* head) {
            
        if(!head)
            return NULL;
        Node* curr = head;
        while(curr)
        {
          Node* nxt = curr->next;
          Node* c = new Node(curr->val);
          curr->next = c;
          c->next = nxt;
          curr = nxt;
        }       
        curr = head;
        while(curr)
        {
            curr->next->random = curr->random ? curr->random->next : NULL;
            curr = curr->next->next;
        }
        Node* ch = head->next,*cc = head->next;
        while(head)
        {
            head->next = head->next->next;
            cc->next = cc->next? cc->next->next: NULL;
            head = head->next;
            cc = cc->next;
            
        }
        return ch;
    }
};