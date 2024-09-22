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
    TreeNode* f(int preInd, int inStart, int inEnd,vector<int>& preorder,vector<int>& inorder)
    {
        if(inStart>inEnd)   return NULL;
        
        int rootval=preorder[preInd];
        int i=inStart;
        while(i<=inEnd && inorder[i]!=rootval){
            i++;
        }
        
        TreeNode* root=new TreeNode(rootval);
        root->left=f(preInd+1,inStart,i-1,preorder,inorder);
        root->right=f(preInd+i-inStart+1,i+1,inEnd,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return f(0,0,n-1,preorder,inorder);
    }
};