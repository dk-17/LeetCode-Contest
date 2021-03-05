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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q1,q2;
        vector<int> odd,even;
        q1.push(root);
        TreeNode* temp;
        while(!(q1.empty() && q2.empty())){
            while(!q1.empty()){
                temp=q1.front();
                odd.push_back(temp->val);
                q1.pop();
                if(temp->left)
                    q2.push(temp->left);
                if(temp->right)
                    q2.push(temp->right);
            }
            for(int i=0;i<odd.size();i++){
                if(odd[i]%2==0)
                    return false;
                if(i!=0 && odd[i-1]>=odd[i])
                    return false;
            }
            odd.clear();
            
            while(!q2.empty()){
                temp = q2.front();
                q2.pop();
                even.push_back(temp->val);
                if(temp->left)
                    q1.push(temp->left);
                if(temp->right)
                    q1.push(temp->right);
            }
            for(int i=0;i<even.size();i++){
                if(even[i]%2!=0)
                    return false;
                if(i!=0 && even[i-1]<=even[i])
                    return false;
            }
            even.clear();      
        }
        return true;
    }
};
