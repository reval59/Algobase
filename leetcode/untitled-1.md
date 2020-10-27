---
description: 'https://leetcode.com/problems/longest-substring-without-repeating-characters/'
---

# 3. Longest Substring Without Repeating Characters

## Problem

Given a string `s`, find the length of the **longest substring** without repeating characters.

**Example 1:**

```text
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

**Example 2:**

```text
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

**Example 3:**

```text
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

**Example 4:**

```text
Input: s = ""
Output: 0
```

**Constraints:**

* `0 <= s.length <= 5 * 104`
* `s` consists of English letters, digits, symbols and spaces.

## Solution

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_map<char, int> indice;
        indice.reserve(s.size());
        int max_len = 0;
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (indice.find(s[i]) != indice.end()) j = max(j, indice[s[i]] + 1);
            indice[s[i]] = i;
            max_len = max(max_len, i - j + 1);
        }
        return max_len;
    }
};
```

* \#hash

