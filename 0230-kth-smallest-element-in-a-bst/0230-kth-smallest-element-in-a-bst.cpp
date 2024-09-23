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
    void f(TreeNode* node, int& cnt, int& ans){
        if(!node)   return; 
        f(node->left,cnt,ans);
        cnt--;
        if(cnt==0)  ans=node->val;
        f(node->right,cnt,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)   return -1;
        int ans=-1;
        f(root,k,ans);
        return ans;
    }
};