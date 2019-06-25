#include <iostream>
#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 归并排序
     * 基于devide & conquer 的思想 自上而下递归
     * 时间复杂度O(logN) 空间复杂度O(logN)
     * @param head 队列头部
     * @return
     */
    ListNode *sortList(ListNode *head) {
        //边界、判空
        if (!head || !head->next) return head;
        //找到中间结点
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *mid = slow->next;
        //拆分成2个List
        slow->next = nullptr;
        return merge(sortList(head), sortList(mid));
    }

private:
    /**
     * 时间复杂度为两个队列长度之和O(n) count(left)+count(right)
     * 空间复杂度O(1)
     */
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode dummy(0);//在栈上分配，会自动释放
        ListNode *tail = &dummy;
        //分别步进，并且使得val较小的node排在前面
        while (left && right) {
            if (left->val > right->val) {
                std::swap(left, right);
            }
            tail->next = left;
            left = left->next;
            tail = tail->next;
        }
        if (left)tail->next = left;
        if (right)tail->next = right;
        return dummy.next;
    }
};

int main() {


    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution solution;
    ListNode *result = solution.sortList(head);

    assert(result->val == 1);
    assert(result->next->val == 2);
    assert(result->next->next->val == 3);
    assert(result->next->next->next->val == 4);

    delete result->next->next->next;
    delete result->next->next;
    delete result->next;
    delete result;

    return 0;
}