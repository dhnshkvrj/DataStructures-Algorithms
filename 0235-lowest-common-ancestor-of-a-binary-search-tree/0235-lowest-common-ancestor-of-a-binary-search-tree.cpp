/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)   return NULL;
        if(root==p || root==q)  return root;
        TreeNode* l=NULL;
        TreeNode* r=NULL;
        if(root->val > p->val || root->val > q->val)
            l=lowestCommonAncestor(root->left,p,q);
        if(root->val < p->val || root->val < q->val)
            r=lowestCommonAncestor(root->right,p,q);
        if(l && r)  return root;
        return l ? l : r;
    }
};