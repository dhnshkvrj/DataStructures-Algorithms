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
    void f(TreeNode* node, int row, map<int,int>& mp){
        if(node==NULL)  return; 
        if(mp.find(row)==mp.end())
            mp[row]=node->val;
        f(node->right,row+1,mp);
        f(node->left,row+1,mp);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int,int>mp;
        f(root,0,mp);

        for(auto i:mp)
            ans.push_back(i.second);
        
        return ans;
    }
};