---
description: 'https://leetcode.com/problems/maximum-product-subarray/'
---

# 152. Maximum Product Subarray

## Problem

Given an integer array `nums`, find the contiguous subarray within an array \(containing at least one number\) which has the largest product.

**Example 1:**

```text
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```

**Example 2:**

```text
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```

## Solution

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int gmax_p = nums[0], max_p = nums[0], min_p = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int temp = max_p;
            max_p = max(nums[i], max(temp * nums[i], min_p * nums[i]));
            min_p = min(nums[i], min(temp * nums[i], min_p * nums[i]));
            gmax_p = max(gmax_p, max_p);
        }
        return gmax_p;
    }
};
```

* \#dp

