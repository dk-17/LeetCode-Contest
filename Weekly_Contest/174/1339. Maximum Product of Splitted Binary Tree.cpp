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
    long long int ans ;
    int mod = 1e9+7;
    void postorder(TreeNode* root){
        if(root == NULL) return;
        if(root->left) postorder(root->left);
        if(root->right) postorder(root->right);
        cout<<root->val<<" ";
        return;
    }
    
    int  Modify( TreeNode* root){
        if(root == NULL) return 0 ;
        int left = Modify(root->left);
        int right = Modify(root->right);
        root->val = left+right+root->val;
        return root->val;
        
    }
    
    int solve(TreeNode* root,int total){
        if(root == NULL) return 0;
       long long  int left =  (root->left)? solve(root->left,total):0;
        
        ans = max(ans,(left * (total-left)));
        long long int right =  (root->right)? solve(root->right,total) : 0;
        
        ans = max(ans,(right * (total-right)));
        return root->val;
    }
    
    
    int maxProduct(TreeNode* root) {
        long long int total = Modify(root);
        
      //  postorder(root);
        ans = 0;
        solve(root,total);
        return ans%mod;
    }
};
