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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        vector<int> nums1,even;
        bool mark = true;
        while(head != NULL){
            if(mark == true){
                nums1.push_back(head->val);
            }else{
                even.push_back(head->val);
            }
            mark = !mark;
            head = head->next;
        }
        for(auto it : even) nums1.push_back(it);
        ListNode* newhead = new ListNode(0);
        ListNode* temp = newhead;
        for(auto it : nums1){
            temp->next = new ListNode(it);
            temp = temp->next; 
        }
        return newhead->next;
    }
};