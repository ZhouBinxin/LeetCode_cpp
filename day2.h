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
        ListNode* dummyHead = new ListNode(0);  // ����һ������ͷ�ڵ�
        ListNode* current = dummyHead;
        int carry = 0;  // ��λ

        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;  // �����λ
            current->next = new ListNode(sum % 10);  // �����½ڵ�洢��ǰλ�Ľ��
            current = current->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;  // �ͷ�����ͷ�ڵ�
        return result;
    }
};

