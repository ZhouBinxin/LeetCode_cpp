#pragma once
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class day2
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);  // 创建一个虚拟头节点
        ListNode* current = dummyHead;
        int carry = 0;  // 进位

        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;  // 计算进位
            current->next = new ListNode(sum % 10);  // 创建新节点存储当前位的结果
            current = current->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;  // 释放虚拟头节点
        return result;
    }
};

