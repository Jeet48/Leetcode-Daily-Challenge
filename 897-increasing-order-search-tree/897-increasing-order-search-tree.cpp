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
    
    TreeNode*inorder(TreeNode *curr,TreeNode *ans) {
          if ( curr == nullptr) return ans;
        TreeNode *now = inorder(curr->left, ans);
        now->right = new TreeNode(curr->val);
        return inorder(curr->right,now->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
      TreeNode *cur = new TreeNode();
        inorder(root,cur);
        return cur->right;
    }
};