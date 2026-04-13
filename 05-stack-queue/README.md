# 栈与队列（Stack & Queue）(需巩固)

## 一、概述

| 容器 | 特点 | 头文件 |
|------|------|--------|
| `stack` | 后进先出（LIFO） | `#include <stack>` |
| `queue` | 先进先出（FIFO） | `#include <queue>` |

---

## 二、stack 常用操作

| 操作 | 代码 | 说明 |
|------|------|------|
| 入栈 | `st.push(x)` | O(1) |
| 出栈 | `st.pop()` | O(1)，无返回值 |
| 访问栈顶 | `st.top()` | O(1) |
| 判空 | `st.empty()` | O(1) |
| 大小 | `st.size()` | O(1) |

---

## 三、queue 常用操作

| 操作 | 代码 | 说明 |
|------|------|------|
| 入队 | `q.push(x)` | O(1) |
| 出队 | `q.pop()` | O(1)，无返回值 |
| 访问队首 | `q.front()` | O(1) |
| 访问队尾 | `q.back()` | O(1) |
| 判空 | `q.empty()` | O(1) |
| 大小 | `q.size()` | O(1) |

---

## 四、经典题目

### 1. 有效的括号（LeetCode 20）

**核心思路**：
- 遇到左括号入栈
- 遇到右括号，检查栈顶是否匹配
- 遍历完后栈必须为空

**代码**：
```cpp
stack<char> st;
unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};

for (char c : s) {
    if (pairs.count(c)) {  // 右括号
        if (st.empty() || st.top() != pairs[c]) return false;
        st.pop();
    } else {  // 左括号
        st.push(c);
    }
}
return st.empty();
```

### 2. 用队列实现栈（LeetCode 225）
**核心思路：** 用两个队列，每次 push 时把新元素放到辅助队列，然后把主队列所有元素移过来，最后交换。

**单队列优化：**

```cpp
void push(int x) {
    q.push(x);
    int n = q.size() - 1;
    while (n--) {
        q.push(q.front());
        q.pop();
    }
}
int pop() {
    int val = q.front();
    q.pop();
    return val;
}
```

## 五、本周完成的栈与队列题
题号	|题目|	知识点|	难度
|-|-|-|-
20	|有效的括号|	stack + 哈希表	|简单
225	|用队列实现栈|	queue	|简单

## 六、需要复习的题目
20. 有效的括号（stack 模板）

225. 用队列实现栈（理解 LIFO vs FIFO）
