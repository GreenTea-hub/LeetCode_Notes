# 哈希表（Hash Table）

## 一、概述

哈希表是一种通过哈希函数将键映射到存储位置的数据结构，可以实现 O(1) 的插入、删除、查找。

**STL 容器**：
- `unordered_map<K, V>`：键值对，K 为键类型，V 为值类型
- `unordered_set<K>`：只存键，不存值

**特点**：
- 平均 O(1) 时间复杂度
- 元素无序
- 空间换时间

---

## 二、经典题型分类

### 1. 两数之和 / 查找配对

**核心思路**：遍历时用哈希表记录“已经看过的元素”，每次检查目标值是否在表中。

| 题号 | 题目 | 核心思路 |
|------|------|---------|
| 1 | 两数之和 | 键为数字，值为下标，找 target - nums[i] |

**模板代码**：
```cpp
unordered_map<int, int> mp;
for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    if (mp.count(complement)) {
        return {mp[complement], i};
    }
    mp[nums[i]] = i;
}
return {};
```

### 2. 存在重复 / 去重
**核心思路**：用 unordered_set 判断元素是否出现过。

题号|	题目|	核心思路|
|-|-|-|
217	|存在重复元素|	遍历时检查是否在集合中
349	|两个数组的交集|	一个数组放 set，遍历另一个找交集

**模板代码（217）**：

```cpp
unordered_set<int> st;
for (int num : nums) {
    if (st.count(num)) return true;
    st.insert(num);
}
return false;
```

### 3. 计数 / 频率统计
**核心思路**：用 unordered_map 统计每个元素出现的次数。

题号|	题目|	核心思路|
|-|-|-|
350	|两个数组的交集 II	|统计 nums1 频率，遍历 nums2 减计数

**模板代码（350）**：

```cpp
unordered_map<int, int> count;
for (int num : nums1) count[num]++;

vector<int> result;
for (int num : nums2) {
    if (count[num] > 0) {
        result.push_back(num);
        count[num]--;
    }
}
return result;
```

### 三、常用操作速查

操作	|unordered_map	|unordered_set
|-|-|-|
头文件	|#include <unordered_map>	|#include <unordered_set>
声明	|unordered_map<int, int> mp	|unordered_set<int> st
插入	|mp[key] = value	|st.insert(x)
查找	|mp.count(key) 或 mp.find(key)	|st.count(x) 或 st.find(x)
删除	|mp.erase(key)	|st.erase(x)
大小	|mp.size()	|st.size()
遍历	|for (auto& p : mp)|	for (int x : st)

### 四、易错点
1.operator[] 会自动插入：int val = mp[key] 如果 key 不存在，会插入 {key, 0}，慎用  

2.查找用 count 或 find：推荐 if (mp.count(key))  

3.遍历时修改：遍历哈希表时不要插入/删除元素（可能导致 rehash）  

### 五、本周完成的哈希表题
题号	|题目	|知识点|	难度
|-|-|-|-|
1	|两数之和	|unordered_map|	简单
217	|存在重复元素|	unordered_set|	简单
349	|两个数组的交集|	unordered_set	|简单
350	|两个数组的交集 II	|unordered_map 计数	|简单
219	|存在重复元素 II	|滑动窗口 + unordered_set|	简单

### 六、需要复习的题目
1. 两数之和（哈希表模板）

350. 两个数组的交集 II（计数模板）
