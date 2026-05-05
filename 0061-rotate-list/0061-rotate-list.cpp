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
    void twopointer(vector<int> &nums,int s,int e){
        while(s<=e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode* temp=head;
        vector<int> nums;
        while(temp!=NULL){
            nums.push_back(temp->val);
            temp=temp->next;
        } 
        int n=nums.size();;
        k=k%n;
        twopointer(nums,0,n-1);
        twopointer(nums,0,k-1);
        twopointer(nums,k,n-1);
        ListNode* ans= new ListNode(nums[0]);
        head=ans;
        for(auto it:nums){
            ListNode* i=new ListNode(it);
            ans->next=i;
            ans=ans->next;
        }
        return head->next;
    }
};