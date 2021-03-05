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
    unordered_map<int,int> umap;
    
    bool DFS(TreeNode* root,int level){
        
        if(root == NULL) return true;
        
        if(level & 1){
            
              if(!(root->val & 1))    return false;
        }
        else if(root->val & 1) return false;
        
        if(umap.find(level) !=umap.end()){
            if(level & 1){
                 if(umap[level]>=root->val) return false;
            }
            else  if(umap[level]<=root->val) return false;
        }
        
        umap[level]=root->val;
       
        
        return DFS(root->left,level+1) && DFS(root->right,level+1);
        
        
    }
    
    
    
    bool isEvenOddTree(TreeNode* root) {
        return DFS(root,1);
    }
};
