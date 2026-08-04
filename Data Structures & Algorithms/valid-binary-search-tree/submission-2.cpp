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
    bool helper(TreeNode* root, int minValue, int maxValue){
        if (root==NULL) return true;
        if (root->val>minValue && root->val<maxValue){
            return helper(root->left,minValue,root->val) &&
                   helper(root->right,root->val,maxValue);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,-1001,1001);
    }
};
