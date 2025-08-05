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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1 = ""; string s2 = "";
        while(l1 != NULL){ s1 += to_string(l1->val); l1 = l1->next;}
        while(l2 != NULL){ s2 += to_string(l2->val); l2 = l2->next;}
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());

        string ans = "";
        int carry = 0 ;
        int sum = 0; int i=0,j=0;
        while(i < s1.size() || j < s2.size() || carry > 0){
            sum = 0;
            if(i < s1.size()){
                sum += s1[i]-'0';
                i++;
            }
            if(j < s2.size()){
                sum += s2[j]-'0';
                j++;
            }
            sum += carry;
            ans = to_string(sum%10) + ans;
            carry = sum/10;
        }
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        for(auto it : ans){
            temp->next = new ListNode(it-'0');
            temp = temp->next;
        }
        return head->next;
    }
};