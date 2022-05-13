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
        Node *curr = NULL;
        Node *head = root;
        
        while(head!=NULL){
            Node *temp = head;
            head = NULL;
            Node *prev = NULL;
            
            while(temp!=NULL){
                
                if(temp->left!=NULL){
                    
                    if(head==NULL){
                        head = temp->left;
                    }
                    
                    if(prev!=NULL){
                        prev->next = temp->left;
                        prev = temp->left;
                    }
                    else {
                        prev = temp->left;
                    }
                }
                
                if(temp->right!=NULL) {
                    if(head==NULL){
                        head = temp->right;
                    }
                    
                    if(prev!=NULL){
                        prev->next=temp->right;
                        prev=temp->right;
                    }
                    else {
                        prev = temp->right;
                        
                    }
                }
                temp=temp->next;
            }
        }
        return root;
    }
};