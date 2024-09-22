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
    // On reaching a particular row for the first time we add the value to the ans
    // because we will reach the rightmost node on each row first
    void f(TreeNode* node, int row, vector<int>&ans){
        if(node==NULL)  return; 
        if(ans.size()==row)     ans.push_back(node->val);
        f(node->right,row+1,ans);
        f(node->left,row+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        f(root,0,ans);
        return ans;
    }
};