26.4.12
# 数组（Array）

## 一、概述

数组是存储在连续内存空间上的相同类型元素的集合。可以通过下标 O(1) 访问任意元素。

**特点**：
- 连续内存，支持随机访问
- 插入/删除（非末尾）需要移动元素，O(n)
- 末尾插入/删除 O(1)（vector 均摊）

---

## 二、经典题型分类

### 1. 双指针（快慢指针）

**适用场景**：原地删除、移动元素、去重

| 题号 | 题目 | 核心思路 |
|---|---|---|
| 27 | 移除元素 | 快指针遍历，慢指针指向要存放的位置 |
| 283 | 移动零 | 同 27，最后补零 |
| 26 | 删除有序数组中的重复项 | 相邻比较 |

**模板代码**：
```cpp
int slow = 0;
for (int fast = 0; fast < nums.size(); fast++) {
    if (nums[fast] != val) {
        nums[slow++] = nums[fast];
    }
}
return slow;  // slow 是新长度
```
### 2. 双指针（相向指针）

**适用场景**：两数之和（有序）、回文判断

| 题号 | 题目	| 核心思路|
|-|-|-|
| 125	| 验证回文串	| 左++，右--，跳过非字母数字
| 345	| 反转字符串中的元音字母	| 左右找元音，交换


**模板代码**：
```cpp
int left = 0, right = s.size() - 1;
while (left < right)
{
    // 移动指针到有效位置
    while (left < right && !isValid(s[left])) left++;
    while (left < right && !isValid(s[right])) right--;
    // 交换/比较
    swap(s[left], s[right]);
    left++;
    right--;
}
```

### 3.滑动窗口(难)

**适用场景**：子数组、子串问题

题号|	题目|	核心思路|
|--|--|--|
219	|存在重复元素 II	|维护大小为 k 的窗口，用 unordered_set

**模板代码**：

```cpp
unordered_set<int> window;
for (int i = 0; i < nums.size(); i++) {
    if (window.count(nums[i])) return true;
    window.insert(nums[i]);
    if (window.size() > k) {
        window.erase(nums[i - k]);
    }
}
return false;
```

### 4. 原地操作（从后向前）
**适用场景**：合并两个有序数组（避免覆盖）

题号|	题目|	核心思路|
|--|--|--|
88	|合并两个有序数组|	从后向前放，p1=m-1, p2=n-1, p=m+n-1
**模板代码**：

```cpp
int p1 = m - 1, p2 = n - 1, p = m + n - 1;
while (p1 >= 0 && p2 >= 0) {
    if (nums1[p1] > nums2[p2]) {
        nums1[p--] = nums1[p1--];
    } else {
        nums1[p--] = nums2[p2--];
    }
}
// nums2 剩余元素拷贝过去
while (p2 >= 0) {
    nums1[p--] = nums2[p2--];
}
```

## 三、常用 STL（vector）
操作|	代码	|时间复杂度|
|--|--|--|
尾部插入	|v.push_back(x)|	O(1) 均摊|
尾部删除|	v.pop_back()|	O(1)|
访问	|v[i]	|O(1)|
大小	|v.size()	|O(1)|
判空	|v.empty()	|O(1)|
## 遍历方式：

```cpp
// 下标 需要用到下标的就用这个
for (int i = 0; i < v.size(); i++) { cout << v[i]; }
// 范围 不需要下标只用遍历的用这个
for (int x : v) { cout << x; }
```

**四、易错点总结**
- vector 越界：访问 v[i] 前确保 i < v.size()
- 循环中删除元素：用双指针，不要在遍历时直接 erase
- 滑动窗口移除元素：移除的是 nums[i - k]，不是 nums[i]
- 从后向前：合并数组时从后向前可以避免覆盖


## 五、本周完成的数组题
| 题号 | 题目 | 知识点 | 难度 |
|---|---|---|---|
| 88 | 合并两个有序数组 | 从后向前双指针 | 简单 |
| 27 | 移除元素 | 快慢指针 | 简单 |
| 283 | 移动零 | 快慢指针 | 简单 |
| 125 | 验证回文串 | 相向双指针 | 简单 |
| 219 | 存在重复元素 II | 滑动窗口 | 简单 |
