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
    TreeNode* f(vector<int>a, int &ind, int upperBound){
        if(ind>=a.size() || a[ind]>upperBound)  return NULL;
        TreeNode* node=new TreeNode(a[ind++]);
        node->left=f(a,ind,node->val);
        node->right=f(a,ind,upperBound);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        return f(preorder,ind,INT_MAX);
    }
};