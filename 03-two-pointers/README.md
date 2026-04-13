# 双指针（Two Pointers）

## 一、概述

双指针是用两个指针（下标）来遍历数组/字符串的技巧，可以将 O(n²) 的暴力解法优化到 O(n)。

**两种主要形态**：
- **同向指针（快慢指针）**：从同一侧出发，一快一慢
- **相向指针（对撞指针）**：从两端出发，向中间移动

---

## 二、快慢指针（同向）

**适用场景**：原地删除、移动元素、去重

**核心思想**：
- `fast` 指针遍历每个元素
- `slow` 指针指向下一个要存放的位置
- 满足条件时，将 `fast` 指向的元素放到 `slow` 位置

| 题号 | 题目 | 核心思路 |
|------|------|---------|
| 27 | 移除元素 | 保留不等于 val 的元素 |
| 283 | 移动零 | 保留非零元素，最后补零 |
| 26 | 删除有序数组中的重复项 | 保留与前一个不同的元素 |

**模板代码（27）**：
```cpp
int slow = 0;
for (int fast = 0; fast < nums.size(); fast++) {
    if (nums[fast] != val) {
        nums[slow++] = nums[fast];
    }
}
return slow;  // slow 是新数组长度
```

**模板代码（283 变体）**：

```cpp
int slow = 0;
for (int fast = 0; fast < nums.size(); fast++) {
    if (nums[fast] != 0) {
        nums[slow++] = nums[fast];
    }
}
while (slow < nums.size()) {
    nums[slow++] = 0;
}
```

## 三、相向指针（对撞）
**适用场景**：回文判断、两数之和（有序数组）、反转

**核心思想**：

- left 从左向右，right 从右向左

- 每次移动一个或两个指针

- 当 left >= right 时结束

题号|	题目|	核心思路
|-|-|-|
125	|验证回文串|	跳过非字母数字，比较忽略大小写
345	|反转字符串中的元音字母	|左右找元音，交换

**模板代码（125）**：

```cpp
int left = 0, right = s.size() - 1;
while (left < right) {
    while (left < right && !isalnum(s[left])) left++;
    while (left < right && !isalnum(s[right])) right--;
    if (tolower(s[left]) != tolower(s[right])) {
        return false;
    }
    left++;
    right--;
}
return true;
```

**模板代码（345）**：

```cpp
int left = 0, right = s.size() - 1;
while (left < right) {
    while (left < right && !isVowel(s[left])) left++;
    while (left < right && !isVowel(s[right])) right--;
    swap(s[left], s[right]);
    left++;
    right--;
}
return s;
```

## 四、本周完成的双指针题
题号	|题目|	类型	|难度
|-|-|-|-|
27	|移除元素	|快慢指针 |	简单
283	|移动零	|快慢指针	|简单
125	|验证回文串|	相向指针	|简单
345	|反转字符串中的元音字母	|相向指针	|简单
88	|合并两个有序数组	|从后向前（特殊）|	简单

## 五、需要复习的题目
27. 移除元素（快慢指针模板）

125. 验证回文串（相向指针模板）
