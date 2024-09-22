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
    TreeNode* f(int postStart, int postEnd, int inStart, int inEnd, map<int,int>& mp,
                vector<int>& inorder, vector<int>& postorder){
        if(postStart<postEnd || inStart>inEnd)      return NULL;
        
        TreeNode* root=new TreeNode(postorder[postStart]);
        int inRoot=mp[root->val];
        int rightSize=inEnd-inRoot;

        root->left=f(postStart-rightSize-1,postEnd,inStart,inRoot-1,mp,inorder,postorder);
        root->right=f(postStart-1,postStart-rightSize,inRoot+1,inEnd,mp,inorder,postorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        return f(n-1,0,0,n-1,mp,inorder,postorder);
    }
};