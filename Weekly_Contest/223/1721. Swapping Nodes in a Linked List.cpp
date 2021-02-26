/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* temp_end=head;
        ListNode* temp_start=head;
        
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        
        int end=count-k+1;
        end--;
        //cout<<"end- "<<end<<endl;
        while(end--){
            temp_end=temp_end->next;
        }
        k--;
        while(k--){
            temp_start=temp_start->next;
        }
       
        swap(temp_start->val,temp_end->val);
        
        return head;
    }
};
