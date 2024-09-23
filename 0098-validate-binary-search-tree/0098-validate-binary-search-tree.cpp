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
    // Inorder traversal
    void f(TreeNode* node, vector<int>& ans){
        if(!node)   return; 
        f(node->left,ans);
        ans.push_back(node->val);
        f(node->right,ans);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)   return true;
        vector<int> inorder;
        f(root,inorder);
        int n=inorder.size();
        for(int i=1;i<n;i++)    
            if(inorder[i-1]>=inorder[i])     return false;
        return true;
    }
};