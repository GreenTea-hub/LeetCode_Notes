# 链表（Linked List）

## 一、概述

链表是由一系列**节点**组成的线性数据结构，每个节点包含**数据域**和**指向下一个节点的指针**。

### 节点结构（LeetCode 标准定义）

```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```
## 数组 vs 链表
特性|	数组|	链表|
|-|-|-
内存	|连续内存	|非连续内存|
随机访问	|O(1)	|O(n)
头部插入/删除	|O(n)|	O(1)
尾部插入/删除	|O(1) 均摊|	O(n)（需遍历）
查找	|O(n)	|O(n)

**结论**: 链表擅长**频繁插入/删除**（尤其头部），数组擅长**随机访问**。

## 二、基本操作
### 1. 遍历链表
```cpp
for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
    cout << cur->val << " ";
}
```

### 2. 插入节点（在 prev 后面插入 newNode）
```cpp
newNode->next = prev->next;
prev->next = newNode;
```

### 3. 删除节点（删除 prev 后面的节点）
```cpp
ListNode* toDelete = prev->next;
prev->next = toDelete->next;
delete toDelete;  // LeetCode 不需要
```

### 4. 虚拟头结点（Dummy Node）
**作用**：简化对头结点的特殊处理（删除/插入头结点时不需要单独判断）。

```cpp
ListNode* dummy = new ListNode(0);
dummy->next = head;
// 使用 dummy 进行操作...
return dummy->next;  // 返回真正的头结点
```

## 三、经典题型
### 1. 反转链表（LeetCode 206）
**核心思路**：用 prev 和 curr 两个指针，逐个反转节点的 next 指向。

### 迭代法代码：

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
```

### 递归法代码：

```cpp
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
```

### 手动模拟（[1,2,3]）：

步骤	|prev|	curr|	操作后链表
|-|-|-|-
初始	|null|	1	|1→2→3
第1轮|	1	|2|	1→null, 2→3
第2轮	|2|	3|	2→1→null, 3→?
第3轮	|3|	null|	3→2→1→null

### 2. 合并两个有序链表（LeetCode 21）
**核心思路**：用虚拟头结点，每次取较小的节点接在后面。

代码：

```cpp
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    
    if (list1 != nullptr) tail->next = list1;
    if (list2 != nullptr) tail->next = list2;
    
    return dummy->next;
}
```

### 3. 环形链表（LeetCode 141）
**核心思路**：快慢指针，slow 走一步，fast 走两步。如果有环，fast 一定会追上 slow。

**代码**：

```cpp
bool hasCycle(ListNode* head) {
    if (head == nullptr) return false;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

### 为什么一定会相遇？

- 当两个指针都进入环后，fast 在追赶 slow

- 每走一步，距离缩小 1

- 环的长度有限，一定会在有限步内追上

### 4. 相交链表（LeetCode 160）
**核心思路**：两个指针分别遍历两个链表，走完自己的链表后转到对方的链表。如果有交点，一定会在交点相遇。

**代码**：

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;
    
    ListNode *pA = headA;
    ListNode *pB = headB;
    
    while (pA != pB) {
        pA = (pA == nullptr) ? headB : pA->next;
        pB = (pB == nullptr) ? headA : pB->next;
    }
    
    return pA;
}
```

**原理**：

- 设 A 不相交部分长度 a，B 不相交部分长度 b，相交部分长度 c

- pA 走的路程：a + c + b

- pB 走的路程：b + c + a

- 两者相等，所以同时到达交点

## 四、常用技巧总结
技巧	|适用场景|	示例
|-|-|-
虚拟头结点	|可能操作头结点|	合并链表、删除节点
快慢指针	|判环、找中点	|环形链表
双指针（等速）	|找交点、倒数第k个	|相交链表
递归	|反转链表、合并链表|	反转链表（递归版）

## 五、易错点
1.**空指针检查**：访问 curr->next 前确保 curr != nullptr

2.**保存 next**：修改 curr->next 前，先保存 curr->next

3.**虚拟头结点的使用**：dummy->next = head，返回 dummy->next

4.**环形链表快慢指针初始化**：都从 head 开始，不能 slow = head, fast = head->next

5.**相交链表比较的是地址**：不是 pA->val == pB->val，而是 pA == pB
