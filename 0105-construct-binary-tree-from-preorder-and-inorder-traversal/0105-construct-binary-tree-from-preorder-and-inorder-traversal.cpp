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
    TreeNode* f(int preStart, int preEnd, int inStart, int inEnd, map<int,int>&mp, 
                vector<int>& preorder, vector<int>& inorder){
        
        if(preStart>preEnd || inStart>inEnd)    return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);

        int inRoot=mp[root->val];
        int numsLeft=inRoot-inStart;

        root->left=f(preStart+1,preStart+numsLeft,inStart,inRoot-1,mp,preorder,inorder);
        root->right=f(preStart+numsLeft+1,preEnd,inRoot+1,inEnd,mp,preorder,inorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        
        return f(0,n-1,0,n-1,mp,preorder,inorder);
    }
};