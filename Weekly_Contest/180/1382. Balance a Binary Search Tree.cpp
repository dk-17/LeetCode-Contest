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
    TreeNode* makeBBST(vector<int>& v,int i,int j ){
        if(i>j) return NULL;
        int mid = (i+j)/2;
       
       
        TreeNode* root = new TreeNode(v[mid]);

     
        root->left = makeBBST(v,i,mid-1);
        root->right = makeBBST(v,mid+1,j);
        return root;
    }
    
    void inorder(vector<int>& v,TreeNode* root){
        if(root == NULL) return;
        inorder(v,root->left);
        v.push_back(root->val);
        inorder(v,root->right);
        return;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(v,root);
        
         return makeBBST(v,0,v.size()-1);
        
    }
};
