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

/**
 * l1 = 1->2->3
 * l2 = 3->2
 */

/**
 * The first approach that comes to my mind, since
 * the numbers are in reverse order in the list,
 * you could sum it in a "natural way" by iterating
 * through the list and making a simple aritmetic sum.
 *
 * You need to check at least one node value exists
 * to make this sum. For exaple, in the case:
 *
 * l1 = 1->2->3
 * l2 = 3->2
 *
 * You check node 2 of both lists, bot exists so you make the sum.
 * 2 + 2 = 4 and that value is a new node in the result list.
 *
 * Then you update the current nodes to the next nodes.
 * So, the next node of l1 has the value 3, whereas
 * the next node of the l2 is nullptr, but that doesn't 
 * mean you cannot make the sum, you need to take in account that 3
 * so you could simply sum 0 and appending as new node of the
 * result list.
 *
 * Next, what happens when the sum is greater than a single digit
 * number ( sum > 9), you need to store the reminder of the sum with 10
 * append it as new node in the result list, and take in account that
 * carry. For example you have 7 + 7 = 14, so you take the reminder 4 as new node
 * and take the carry for the next sum in this case 1.
 *
 * So the algorithm would be: 
 * While at least one of the nodes isn't nullptr you can keep making sums.
 * Then define the values that will be added, check if the node is nullptr
 * to make the value of the node equal to 0 and thus don't affect the
 * existing value.
 *
 * Make the sum taking into account the reminder.
 * Check if the sum is greater than 9, in that
 * case, get the reminder, append it as new node
 * and save the carry.
 * In the other case just add the result as new and
 * make the carry igual to 0;
 *
 * Return the head of the result list.
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        
        int l1_val = 0;
        int l2_val = 0;
        int sum = 0;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry)
        {
            l1_val = l1 != nullptr ? l1->val : 0;
            l2_val = l2 != nullptr ? l2->val : 0;

            sum = l1_val + l2_val + carry;

            if (sum > 9)
            {
                int rem = sum % 10;
                curr->next = new ListNode(rem);
                curr = curr->next;
                carry = 1;
            }
            else
            {
                curr->next = new ListNode(sum);
                curr = curr->next;
                carry = 0;
            }

            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
        }

        return head->next;
    }
};
