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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int> list;
        while(head != NULL){
            list.push_back(head->val);
            head = head->next;
        }
        unordered_map<int,int> mapp;
        for(auto it : nums) mapp[it]++;
        
        vector<int> ans;
        for(int i=0; i<list.size(); i++){
            if(mapp.find(list[i]) == mapp.end()){
                ans.push_back(list[i]);
            }
        }
        ListNode* newhead = new ListNode(0);
        ListNode* temp = newhead;
        for(auto it : ans){
            temp->next = new ListNode(it);
            temp = temp->next;
        }
        return newhead->next;
    }
};