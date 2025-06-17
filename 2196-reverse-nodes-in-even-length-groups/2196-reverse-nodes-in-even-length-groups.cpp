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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<vector<int>> nums;
        int k = 1;
        vector<int> temp;
        while(head != NULL){
            temp.push_back(head->val);
            if(temp.size() == k) {
                if(temp.size() % 2 == 0){
                    reverse(temp.begin(),temp.end());
                    nums.push_back(temp);
                }
                else nums.push_back(temp);
                k++;
                temp.clear();
            }
            head = head->next;
        }
        if(temp.size() > 0){
            if(temp.size()%2 == 0){
                reverse(temp.begin(),temp.end());
                nums.push_back(temp);
            }
            else nums.push_back(temp);
        }
        ListNode* nhead = new ListNode(0);
        ListNode* ntemp = nhead;
        for(auto it : nums){
            for(auto i : it){
                ntemp->next = new ListNode(i);
                ntemp = ntemp->next;
            }
        }
        return nhead->next;
    }
};