# 字符串（String）

## 一、概述

`string` 是 C++ 中的字符串类型，本质是字符的动态数组，支持类似 `vector` 的操作。

**头文件**：`#include <string>`

---

## 二、常用操作

| 操作 | 代码 | 说明 |
|------|------|------|
| 获取长度 | `s.size()` 或 `s.length()` | O(1) |
| 访问字符 | `s[i]` | O(1) |
| 拼接 | `s += "abc"` | O(n) |
| 查找 | `s.find("sub")` | O(n)，返回下标或 `string::npos` |
| 子串 | `s.substr(pos, len)` | O(len) |
| 尾部添加 | `s.push_back(c)` | O(1) |
| 尾部删除 | `s.pop_back()` | O(1) |
| 反转 | `reverse(s.begin(), s.end())` | O(n)，需 `<algorithm>` |

---

## 三、字符判断与转换（`<cctype>`）

| 函数 | 作用 |
|------|------|
| `isalnum(c)` | 是否是字母或数字 |
| `isalpha(c)` | 是否是字母 |
| `isdigit(c)` | 是否是数字 |
| `islower(c)` | 是否是小写 |
| `isupper(c)` | 是否是大写 |
| `tolower(c)` | 转小写 |
| `toupper(c)` | 转大写 |

---

## 四、经典题目

### 1. 反转字符串中的单词 III（LeetCode 557）

**核心思路**：双指针找单词边界，用 `reverse` 反转每个单词

```cpp
int start = 0;
for (int i = 0; i <= s.size(); i++) {
    if (i == s.size() || s[i] == ' ') {
        reverse(s.begin() + start, s.begin() + i);
        start = i + 1;
    }
}
return s;
```

### 2. 反转字符串中的元音字母（LeetCode 345）
**核心思路：** 相向双指针，找到元音后交换

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

## 3. 最长公共前缀（LeetCode 14）
**核心思路：** 逐列比较，注意越界检查

```cpp
string result = "";
for (int i = 0; i < strs[0].size(); i++) {
    char c = strs[0][i];
    for (int j = 1; j < strs.size(); j++) {
        if (i >= strs[j].size() || strs[j][i] != c) {
            return result;
        }
    }
    result.push_back(c);
}
return result;
```

## 五、本周完成的字符串题
题号	|题目	|知识点|	难度
|-|-|-|-
557	|反转字符串中的单词 III|	string + reverse|	简单
345	|反转字符串中的元音字母	相向双指针|	简单
14	|最长公共前缀	|字符串遍历	|简单
125	|验证回文串	|相向指针 + isalnum|	简单

## 六、需要复习的题目
557. 反转单词（reverse 区间）

14. 最长公共前缀（越界检查）
