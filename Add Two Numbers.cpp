/*
Question- You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
link-https://leetcode.com/problems/add-two-numbers/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(l1==NULL and l2==NULL)
            return NULL;
        else if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        int a=l1->val + l2->val;
        ListNode *p= new ListNode(a%10);
        p->next=addTwoNumbers(l1->next,l2->next);

        if(a>=10)
        {
            p->next=addTwoNumbers(p->next,new ListNode(1));
        }
        return p;
    }
};
/*
Editorial-
Just like how you would sum two numbers on a piece of paper, we begin by summing the least-significant digits,
 which is the head of l1l1 and l2l2. Since each digit is in the range of 0 \ldots 90…9, summing two digits may "overflow".
 For example 5 + 7 = 125+7=12. In this case, we set the current digit to 22 and bring over the carry = 1carry=1 to the next iteration.
 carrycarry must be either 00 or 11 because the largest possible sum of two digits (including the carry) is 9 + 9 + 1 = 199+9+1=19.
*/
