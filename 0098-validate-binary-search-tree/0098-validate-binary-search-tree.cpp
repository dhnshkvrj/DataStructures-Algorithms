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
    bool f(TreeNode* root, long long mini, long long maxi){
        if(!root)   return true;
        if(root->val<=mini || root->val>=maxi)  return false;
        if(root->left && root->val<=root->left->val)     return false;
        if(root->right && root->val>=root->right->val)   return false;
        mini=min(mini,(long long)root->val);
        maxi=max(maxi,(long long)root->val);
        return f(root->left,mini,root->val) && f(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)   return true;
        return f(root,LLONG_MIN,LLONG_MAX);
    }
};