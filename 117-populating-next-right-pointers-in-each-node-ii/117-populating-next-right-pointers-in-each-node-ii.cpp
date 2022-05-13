/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *curr = nullptr, *head=root;
        
        while(head){
          Node *prev = nullptr, *temp = head;
            head = nullptr;
            
            while(temp){
                for(const auto& lr : {temp->left, temp->right}){
                    if(lr==nullptr) continue;
                    if(head==nullptr) head = lr;
                    if(prev) prev->next = lr;
                    prev=lr;
                }
                temp = temp->next;
            }
        }
        return root;
    }
};