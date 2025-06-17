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
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int> s;
        for(auto it : nums){
            s.insert(it);
        }
        int count = 0;
        int check = 0;
        while(head != NULL){
            check = head->val;
            while(head and s.count(head->val)){
                check = head->val;
                head = head->next;
            }
            if(s.count(check)) count++;
            if(head) head = head->next;
        }
        return count;
    }
};