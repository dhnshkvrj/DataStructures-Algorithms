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
    void f(TreeNode* node, int row, int col, map<int,vector<pair<int,int>>>& mp){
        if(node==NULL)  return;
        mp[col].push_back({row,node->val});
        f(node->left,row+1,col-1,mp);
        f(node->right,row+1,col+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>>mp;
        f(root,0,0,mp);

        for(auto &i:mp)
            sort(i.second.begin(),i.second.end());
    
        for(auto x:mp){
            vector<int> temp;
            auto v=x.second;
            for(auto i:v)
                temp.push_back(i.second);
            ans.push_back(temp);
        }

        return ans;
    }
};