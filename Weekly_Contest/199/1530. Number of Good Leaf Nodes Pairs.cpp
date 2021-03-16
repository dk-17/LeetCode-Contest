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
     int count = 0;
    int countPairs(TreeNode* root, int distance) {
        DFS(root,distance);
        return count ;
    }
    
    vector<int> DFS(TreeNode* root, int dis){
        vector<int> p = {};
        if(root == NULL) return p;
        
        vector<int> left = DFS(root->left,dis);
        vector<int> right = DFS(root->right,dis);
        
        if(left.size() == 0 && right.size() == 0){
            p.push_back(1);
            return p;
        }
        
        for(int i = 0; i < left.size(); i++){
            for(int j = 0; j < right.size(); j++){
                if(left[i] + right[j] <= dis)
                    count++;
            }
        }
        
        
        for(int i = 0; i < left.size(); i++){
            left[i]++;
            p.push_back(left[i]);
        }
        
        for(int i = 0; i <right.size(); i++){
            right[i]++;
            p.push_back(right[i]);
        }
        
        return p;
        
        
        
        
    }
    
};
