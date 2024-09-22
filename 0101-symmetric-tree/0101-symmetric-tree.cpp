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
    bool f(TreeNode* p, TreeNode* q){
        if(p && q)      return p->val==q->val && f(p->left,q->right) && f(p->right,q->left);
        if(!p && !q)    return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)  return true;
        return f(root->left,root->right);
    }
};