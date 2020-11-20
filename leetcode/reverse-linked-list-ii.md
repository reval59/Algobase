---
description: 'https://leetcode.com/problems/reverse-linked-list-ii/'
---

# Reverse Linked List II

## Problem

Reverse a linked list from position _m_ to _n_. Do it in one-pass.

**Note:** 1 ≤ _m_ ≤ _n_ ≤ length of list.

**Example:**

```text
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
```

## Solution

```cpp
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode *prev = head;
        int i = 1;
        for (; i < m - 1; ++i) {
            prev = prev->next;
        }
        ListNode *current = (m > 1) ? prev->next : head;
        ListNode *next = current->next;
        if (m > 1) i += 1;
        for (; i < n; ++i) { 
            ListNode *temp = next->next;
            if (i == m) current->next = nullptr;
            next->next = current;
            current = next;
            next = temp;
        }
        if (m > 1) {
            prev->next->next = next;
            prev->next = current;
            ListNode *t = head;
            return head;
        } else {
            prev->next = next;
            return current;
        }        
    }
};
```

* \#linkedlist

