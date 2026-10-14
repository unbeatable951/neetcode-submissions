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

    bool isValid(TreeNode* root,long long minval,long long maxval)
    {
        if(root==nullptr)
        {
            return true;
        }

        if(root->val <= minval || root->val >= maxval)
        {
            return false;
        }
        return isValid(root->left,minval,root->val)
             && isValid(root->right,root->val,maxval);


    }
    bool isValidBST(TreeNode* root) {

        return isValid(root,LLONG_MIN,LLONG_MAX);
        
    }
};
