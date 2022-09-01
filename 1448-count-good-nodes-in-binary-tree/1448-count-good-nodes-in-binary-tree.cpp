/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int count=0;
        if(!root)
            return count;
        countgoodnodes(root,count,root->val);
        
        return count;
    }
    
    void countgoodnodes(TreeNode* root, int& count, int maxforthissetup)
    {
        if(root==NULL)
            return;
        if(root->val>=maxforthissetup)
        {
            count++;
            maxforthissetup = root->val;
        }
        countgoodnodes(root->left,count, maxforthissetup);
        countgoodnodes(root->right,count, maxforthissetup);
    }
};