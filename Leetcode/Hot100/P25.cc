//
// Created by 13345 on 2024/3/8.
//

//K个一组翻转链表
//给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
//
//k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
//
//你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

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

// O(1)的空间复杂度，原地操作
class Solution_1 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy;
        while (head != nullptr) {
            ListNode* p = pre;
            int count = 0;
            while (p != nullptr && count < k) {
                p = p->next;
                ++count;
            }
            // 这里不能用 count < k来判断，当count == k时，p可能指向nullptr
            // pre->val->nullptr, k = 2, 可以达成 count == k，但此时p == nullptr
            // 注意边界条件的物理含义
            if (p == nullptr) {
                return dummy->next;
            }
            // ListNode* nex = p->next;
            std::pair<ListNode*, ListNode*> res = subReverse(head, p);
            head = res.first;
            p = res.second;
            pre->next = head;
            // p->next = nex;
            pre = p;
            head = p->next;

        }

        return dummy->next;

    }

    // 反转head --> tial这一段子链表
    std::pair<ListNode*, ListNode*> subReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }
};

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

// 借助双端队列 deque简化代码
class Solution_2 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        std::deque<struct ListNode*> queue;
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while (head != nullptr) {
            int count = 0;
            while (head != nullptr && count < k) {
                queue.push_back(head);
                head = head->next;
                ++count;
            }
            if (count != k) {
                while (!queue.empty()) {
                    tail->next = queue.front();
                    queue.pop_front();
                    tail = tail->next;
                }

            } else {
                while (!queue.empty()) {
                    tail->next = queue.back();
                    queue.pop_back();
                    tail = tail->next;
                }

            }
        }
        tail->next = nullptr;
        return dummy->next;

    }
};