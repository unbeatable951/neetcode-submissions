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
    int pathsum(TreeNode* root,int& maxSum)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int lsum = max(0,pathsum(root->left,maxSum));
        int rsum = max(0,pathsum(root->right,maxSum));

        int current = root->val+lsum+rsum;

        maxSum = max(maxSum,current);

        return root->val+max(lsum,rsum);

    }
    int maxPathSum(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }

        int maximumSum = INT_MIN;
        pathsum(root,maximumSum);

        return maximumSum;
    }
};
