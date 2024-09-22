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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)  return 0;
        unsigned int maxsize=0;         // To prevent overflow
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            // We use min_ind to make sure we assign nodes at each level with 
            // indexes starting from 1 so that ind doesnt reach INT_MAX for 
            // large tree sizes
            int min_ind=q.front().second;
            
            unsigned int size=q.size();
            unsigned int first=0, last=0;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                unsigned int ind=q.front().second;
                if(i==0)        first=ind;
                if(i==size-1)   last=ind;
                q.pop();
                if(node->left != NULL)
                    q.push({node->left,2*ind+1-min_ind});
                
                if(node->right != NULL)
                    q.push({node->right,2*ind+2-min_ind});
            }
            maxsize=max(maxsize,last-first+1);
        }        
        return maxsize;
    }
};