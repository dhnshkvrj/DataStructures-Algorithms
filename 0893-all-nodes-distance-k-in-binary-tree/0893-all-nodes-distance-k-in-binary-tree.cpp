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
    int count(TreeNode* node){
        if(!node)   return 0;
        return 1+ count(node->left) + count(node->right);
    }
    void buildAdj(TreeNode* node, vector<int> adj[]){
        if(!node)   return;
        int u=node->val;
        if(node->left){
            int v=node->left->val;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(node->right){
            int v=node->right->val;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        buildAdj(node->left,adj);
        buildAdj(node->right,adj);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int n=count(root);
        vector<int> adj[n+1];
        buildAdj(root,adj);

        vector<int> ans;
        vector<int> vis(n+1,0);
        
        queue<pair<int,int>> q;
        q.push({target->val,0});

        while(!q.empty()){
            int node=q.front().first;
            int dist=q.front().second;
            q.pop();

            vis[node]=1;
            
            if(dist==k)     
                ans.push_back(node);
            
            for(auto i:adj[node])
                if(!vis[i] && dist+1<=k)
                    q.push({i,dist+1});
        }
            
        return ans;
    }
};