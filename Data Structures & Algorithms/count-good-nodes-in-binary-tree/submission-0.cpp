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

    int countNodes(TreeNode*root,int maxi)
    {
       if(root==nullptr)
       {
        return 0;
       }
       int current = (root->val>=maxi) ? 1:0;
       int newMax = max(root->val,maxi);

       return current + countNodes(root->left,newMax) +      countNodes(root->right,newMax);

    }
    int goodNodes(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
    
        return countNodes(root,root->val);
    }
};
