# 二分查找（Binary Search）

## 一、概述

二分查找是在**有序数组**中快速查找目标值的算法，每次将搜索范围缩小一半。

**时间复杂度**：O(log n)  
**空间复杂度**：O(1)

**前提条件**：数组必须有序（升序或降序）

---

## 二、标准二分查找模板（闭区间）

```cpp
int left = 0, right = nums.size() - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;  // 防止溢出
    if (nums[mid] == target) {
        return mid;
    } else if (nums[mid] < target) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
return -1;  // 没找到
```

**关键点：**

- 循环条件 left <= right（闭区间）

- mid 计算用 left + (right - left) / 2

- 边界更新：left = mid + 1，right = mid - 1

## 三、变体1：搜索插入位置
### 区别：找不到时返回应该插入的位置，而不是 -1

题号|	题目|	核心思路
|-|-|-|
35	|搜索插入位置	|循环结束后返回 left

**核心代码**：

```cpp
int left = 0, right = nums.size() - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
        return mid;
    } else if (nums[mid] < target) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
return left;  // 插入位置
```

**为什么返回 left？** 循环结束时，left 指向第一个大于 target 的位置。

## 四、变体2：查找左右边界

**适用场景：** 数组中有重复元素，需要找到第一个和最后一个位置

题号	|题目	|核心思路
|-|-|-|
34|	在排序数组中查找首尾位置	|两次二分，分别找左右边界

**找左边界：**

```cpp
int left = 0, right = nums.size() - 1;
int leftBound = -1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
        leftBound = mid;
        right = mid - 1;   // 继续往左找
    } else if (nums[mid] < target) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
```

**找右边界：**

```cpp
left = 0, right = nums.size() - 1;
int rightBound = -1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
        rightBound = mid;
        left = mid + 1;    // 继续往右找
    } else if (nums[mid] < target) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
```

## 五、变体3：数学问题
题号	|题目|	核心思路
|-|-|-|
69	|x 的平方根	|在 [0, x] 中找满足 mid² ≤ x 的最大 mid

**核心代码：**

```cpp
int left = 1, right = x, ans = 0;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (mid <= x / mid) {  // 用除法防止溢出
        ans = mid;
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
return ans;
```

## 六、易错点
1.循环条件：闭区间用 <=，左闭右开用 <

2.溢出：用 left + (right - left) / 2 而不是 (left + right) / 2

3.边界更新：left = mid + 1，right = mid - 1（不要写成 mid）

4.除法防溢出：mid * mid <= x 可能溢出，用 mid <= x / mid

## 七、本周完成的二分查找题
题号|	题目	|类型	|难度
|-|-|-|-|
704	|二分查找|	标准模板	|简单
35	|搜索插入位置	|找插入点|	简单
34	|在排序数组中查找首尾位置|	找左右边界|	中等
69	|x 的平方根|	数学二分|	简单

## 八、需要复习的题目
704. 二分查找（标准模板）

35. 搜索插入位置（返回 left）

34. 查找首尾位置（两次二分）
