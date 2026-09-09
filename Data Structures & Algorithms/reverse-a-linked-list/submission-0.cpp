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
 * --- Recursive approach ---
 *
 * I read the editorial and I think
 * I can identify the mechanics behind the code
 * and thus the key ideas.
 *
 * First, think about how you can reverse the link
 * of one node and set it to point to our current node.
 *
 * For example: 4 -> 5 -> nullptr
 * The basic operation is to set the next 
 * attribute of my next node to pointing to me.
 *
 * That can be achieve by the following code:
 * node4->next->next = node4;
 * node4->next->next = node5->next = node4;
 *
 * Now our chain of links looks like: 
 * 4 <-> 5
 * So, we need to set the next pointer of our
 * current node to nullptr to avoid circular reference.
 *
 * Excellent we have found how to change the direction
 * of the pointers, the other problem is how to return
 * our new head, since our new head will always be at 
 * the end of our list, so how can we travel through
 * our list, reach the end node and passing up through
 * the recursion calls (recursion tree).
 *
 * That sounds like a return statement, let's say
 * a basic example. Say we have the list
 *
 * head -> 3 -> 4 -> 5 -> nullptr
 *
 * We are in the node 3, also the head is at the node 3,
 * then we move to node 4 calling the function again,
 * what happens at this point? We need to save that "current head"
 * and keep moving through the list. But how we can retrieve
 * that value, how the node 3 gets the head returned by node 4
 * and node 4 gets the head returned by node 5. Well, I think
 * that is possible by setting a variable that saves what the
 * function returns recursively. Our stop condition would be
 * if the node hasn't a next node, in that point we can return
 * the current head, that is the last node.
 *
 * Let's say a basic example of this.
 * ListNode* getLastHead(ListNode* head)
 * {
 *      ListNode* currHead = head;
 *      if (head->next)
 *      {
 *          currHead = getLastHead(head->next);
 *      }
 *      return currHead;
 * }
 *
 * So, this code do the following, create a pointer to the current head
 * (that is our current node where we are) and it makes sense only
 * when you reach the last node, because when you reach the last node
 * you have a pointer to this node, because the last node has not a next 
 * node, the recursion call ends and currHead is returned, that is a pointer
 * to the last node traveling up the recursion call.
 *
 * So I think with these two problems clear, we can build an implementation. 
 * The recursion approach is difficult, but I thin develop the skill of
 * think about the problem like sub problems and put basic implementation of
 * that subproblems could be useful.
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* currHead = head;
        if (head->next)
        {
            currHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;

        return currHead;

    }
};
