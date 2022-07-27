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
    
    
    TreeNode* rightmost(TreeNode* root)
    {
        if(root->right==NULL)
            return root;
        return rightmost(root->right);
    }
    
    void flatten(TreeNode* root) {
      if(root==NULL)
          return;
        TreeNode* lft;
        TreeNode* rgt;
        
        while(root)
        {
            if(root->left)
            {
                rgt = rightmost(root->left);
                lft = root->right;
                root->right = root->left;
                root->left = NULL;
                rgt->right = lft;
            }
            root = root->right;
        }
    }
};