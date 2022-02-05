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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> v;
        
        for(auto node:lists)
        {
            while(node)
            {
               v.push_back(node->val);
                node=node->next;
                    
            }
        }
        if(v.size()==0) return NULL;
        
        sort(v.begin(),v.end());
        
        ListNode* head = new ListNode(v[0]);
        
        ListNode* tmp = head;
        
        for(int i =1;i<v.size();i++)
        {
            tmp->next = new ListNode(v[i]);
            tmp=tmp->next;
            
        }
        return head;
        
    }
};