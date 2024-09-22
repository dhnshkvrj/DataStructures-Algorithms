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
    void findParent(TreeNode* node, map<int,TreeNode*>& parent){
        if(!node)   return;
        if(node->left)      parent[node->left->val]=node;
        if(node->right)     parent[node->right->val]=node;
        findParent(node->left,parent);
        findParent(node->right,parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<int,TreeNode*> parent;
        findParent(root,parent);

        vector<int>ans,vis(500+1,0);

        queue<pair<TreeNode*,int>>q;
        q.push({target,0});

        while(!q.empty()){
            TreeNode* node=q.front().first;
            int dist=q.front().second;  
            q.pop();      

            vis[node->val]=1;
            if(dist==k)     ans.push_back(node->val);
            
            if(dist+1<=k){
                if(node->left && !vis[node->left->val])      q.push({node->left,dist+1});    
                if(node->right && !vis[node->right->val])     q.push({node->right,dist+1});
                if(parent.find(node->val)!=parent.end() && !vis[parent[node->val]->val])    
                    q.push({parent[node->val],dist+1});
            }              
        }
        return ans;
    }
};