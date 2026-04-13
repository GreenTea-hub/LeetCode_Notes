# 优先队列（Priority Queue）(需巩固)

## 一、概述

`priority_queue` 是一个自动排序的容器，内部用**堆**实现。默认是最大堆（最大值在队首）。

**头文件**：`#include <queue>`

---

## 二、常用操作

| 操作 | 代码 | 时间复杂度 |
|------|------|-----------|
| 插入 | `pq.push(x)` | O(log n) |
| 删除堆顶 | `pq.pop()` | O(log n) |
| 访问堆顶 | `pq.top()` | O(1) |
| 判空 | `pq.empty()` | O(1) |
| 大小 | `pq.size()` | O(1) |

---

## 三、创建最小堆

```cpp
// 方法1：使用 greater
priority_queue<int, vector<int>, greater<int>> pq;

// 方法2：存入负数（技巧）
priority_queue<int> pq;
pq.push(-x);  // 取出来时用 -pq.top()
```

## 四、经典题目
**数组中的第K个最大元素（LeetCode 215）**
**核心思路：** 维护一个大小为 k 的最小堆，堆顶就是第 k 大的元素

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
for (int num : nums) {
    pq.push(num);
    if (pq.size() > k) {
        pq.pop();
    }
}
return pq.top();
```
**为什么这样做？**

- 堆里保存着最大的 k 个元素

- 堆顶是这 k 个元素中最小的 → 第 k 大的元素

## 五、本周完成的优先队列题
题号	|题目	|知识点	|难度
|-|-|-|-
215	|数组中的第K个最大元素	|最小堆|	中等

## 六、需要复习的题目
215. 第K个最大元素（最小堆模板）
