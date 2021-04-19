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
    vector<vector<int>> v;
    int ans;
     unordered_map<int,int> umap;
    
    void DFS(TreeNode* root){
       if(root->left == NULL && root->right == NULL){
            umap[root->val]++;
            int count = 0;
            for(auto  it =  umap.begin(); it!= umap.end();it++){
                if(it->second %2 !=0 ){
                    count++;
                    if(count>1) {
                        umap[root->val]--;
                        return;
                    }
                }     
            }
           ans++;
           umap[root->val]--;
           return ;      
       }
     
       umap[root->val]++;
        
       if(root->left)  DFS(root->left);
       if(root->right)  DFS(root->right);
       
        umap[root->val]--;
           
    }
    
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        ans=0;
        DFS(root);   
       
        return ans;   
    }
};
