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

    bool isSame(TreeNode* root, TreeNode* subroot)
    {

        if(root==nullptr && subroot==nullptr)
        {
            return true;
        }

        if(root==nullptr || subroot== nullptr)
        {
            return false;
        }

        if(root->val !=subroot->val)
        {
            return false;
        }

        return isSame(root->left,subroot->left)
              && isSame(root->right,subroot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr || subRoot==nullptr)
        {
            return false;
        }

        return isSame(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
  
    }
};
