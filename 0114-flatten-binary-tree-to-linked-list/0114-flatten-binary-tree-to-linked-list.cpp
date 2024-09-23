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
    void f(TreeNode* node, TreeNode* &temp){
        if(node==NULL)
            return;
        temp->right=new TreeNode(node->val);
        temp->left=NULL;
        temp=temp->right;
        f(node->left,temp);
        f(node->right,temp);
        return;
    }
    void flatten(TreeNode* root) {
        if(!root)   return;
        TreeNode* head=new TreeNode(0);     // dummy node
        TreeNode* temp=head;
        f(root,temp);
        root->right=head->right->right;     // we skip dummy node         
        root->left=NULL;                    // left points to NULL
        // We can't directly assign root=head->right; as its not passed by ref
        // But we can change location to whoch root's left or right points to
    }
};