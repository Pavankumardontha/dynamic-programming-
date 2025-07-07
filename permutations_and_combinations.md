# Finding the Number of Possible Ways to Form a Target Sum

This document outlines two variations of a common dynamic programming problem: counting the number of ways to reach a target sum using given elements (e.g., coins). Both variations can be solved using **1D Dynamic Programming** in an iterative manner, although the recursive formulations may differ in complexity.

---

## Variation 1: **Permutations are Considered Different**

### 🔹 Problem Statement:
Given a list of coins (e.g., `[2, 3, 5]`) and a target sum (e.g., `9`), find the number of **sequences** (order matters) that sum up to the target.

### 🔸 Example:
**coins = {2, 3, 5}, target = 9**
- Valid permutations (8 total):
  - 2+2+5
  - 2+5+2
  - 5+2+2
  - 3+3+3
  - 2+2+2+3
  - 2+2+3+2
  - 2+3+2+2
  - 3+2+2+2

### 🔹 Iterative 1D DP Code:
```cpp
int dp[target + 1] = {0};
dp[0] = 1;
for (int i = 1; i <= target; i++) {
    for (int j = 0; j < n; j++) {
        if (i - coins[j] >= 0)
            dp[i] += dp[i - coins[j]];
    }
}
```

### 🔹 Recursive Version:
```cpp
int countPermutations(int target, vector<int>& coins) {
    if (target == 0)
        return 1;
    if (target < 0)
        return 0;

    int ways = 0;
    for (int coin : coins) {
        ways += countPermutations(target - coin, coins);
    }
    return ways;
}
```

### 🔸 DP Conversion:
Even in recursive → DP conversion, **only `target`** changes. So, **1D DP** is sufficient.

---

## Variation 2: **Only Combinations (Order Doesn't Matter)**

### 🔹 Problem Statement:
Given a list of coins (e.g., `[2, 3, 5]`) and a target sum (e.g., `9`), count the number of **unique sets** (order doesn't matter) that sum to the target.

### 🔸 Example:
**coins = {2, 3, 5}, target = 9**
- Valid combinations (3 total):
  - 2+2+5
  - 3+3+3
  - 2+2+2+3

### 🔹 Iterative 1D DP Code:
```cpp
int dp[target + 1] = {0};
dp[0] = 1;
for (int i = 0; i < n; i++) {
    for (int j = coins[i]; j <= target; j++) {
        dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
    }
}
```

### 🔹 Recursive Version:
```cpp
int countCombinations(int index, int target, vector<int>& coins) {
    if (target == 0)
        return 1;
    if (target < 0 || index == coins.size())
        return 0;

    int take = countCombinations(index, target - coins[index], coins);
    int notTake = countCombinations(index + 1, target, coins);

    return take + notTake;
}
```

### 🔸 DP Conversion:
Recursive version has **two changing parameters** (`index`, `target`) → Requires **2D DP**.

But in the iterative bottom-up version, by fixing the coin loop first, the solution can be optimized to **1D DP** by avoiding overcounting permutations.

---

## Summary:
| Variation | Order Matters | Recursive Params | DP Dimension (Recursion) | Optimized DP (Iterative) |
|----------|----------------|------------------|---------------------------|---------------------------|
| 1        | ✅ Yes         | target           | 1D                        | 1D                        |
| 2        | ❌ No          | index, target    | 2D                        | 1D                        |

By understanding how order affects the structure of the problem, we choose the correct DP formulation and optimize accordingly.
