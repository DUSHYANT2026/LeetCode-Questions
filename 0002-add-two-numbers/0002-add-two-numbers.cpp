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
       ListNode* dummy=new ListNode();
       ListNode* temp=dummy;
       int carry=0;
       while(l1 != NULL || l2!=NULL || carry){
           int sum=0;
           if(l1 != NULL){
               sum+=l1->val;
               l1=l1->next;
           }
           if(l2 != NULL){
               sum+=l2->val;
               l2=l2->next;
           }
           sum+=carry;
           carry=sum/10;
           ListNode* node=new ListNode(sum%10);
           temp->next=node;
           temp=temp->next;
       }
       return dummy->next;
    }
};


// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         string s1,s2;

//         while(l1 != NULL){
//             s1 += to_string(l1->val);
//             l1 = l1->next;
//         }
//         while(l2 != NULL){
//             s2 += to_string(l2->val);
//             l2 = l2->next;
//         }
//         reverse(s1.begin(),s1.end());
//         reverse(s2.begin(),s2.end());
//         long long ans = stoll(s1) + stoll(s2);
//         vector<int> nums;
//         if(ans == 0) nums.push_back(0);
//         while(ans != 0){
//             nums.push_back(ans%10);
//             ans = ans/10;
//         }
//         ListNode* head = new ListNode(0);
//         ListNode* temp = head;
//         for(auto it : nums){
//             temp->next = new ListNode(it);
//             temp = temp->next;
//         }
//         return head->next;
//     }
// };