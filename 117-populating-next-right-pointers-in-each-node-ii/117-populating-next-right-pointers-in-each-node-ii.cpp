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
        
        Node *newRoot=root;
        while(root!=NULL){
            
            Node *dummy = new Node;
            Node *temp = dummy;
            
            while(root!=NULL){
                if(root->left){
                    dummy->next=root->left;
                    dummy=dummy->next;
                }
                if(root->right){
                    dummy->next=root->right;
                    dummy=dummy->next;
                }
                root = root->next;
            }
            root=temp->next;
        }
        return newRoot;
    }
};