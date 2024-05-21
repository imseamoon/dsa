# [Sum of All Subset XOR Totals](https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/)

## Problem

You are given an integer array `nums`. The XOR total of an array is defined as the bitwise XOR of all its elements, or `0` if the array is empty.

- For example, the XOR total of the array `[2,5,6]` is `2 XOR 5 XOR 6 = 1`.

You are also given an integer `k`.

- You need to find the sum of all the XOR totals for every subset of `nums` modulo `k`.

- Note: Subsets with the same elements should be counted multiple times.

An array `a` is a subset of an array `b` if `a` can be obtained from `b` by deleting some (possibly zero) elements of `b`.

## Example

Input: `nums = [1,3]`, `k = 6`
Output: `6`
Explanation: The XOR subsets are `[0]`, `[1]`, `[3]`, and `[1,3]`.
Their respective XOR totals are `0`, `1`, `3`, and `2`.
The sum of the XOR totals is `0 + 1 + 3 + 2 = 6`.

## Constraints

- `1 <= nums.length <= 12`
- `1 <= nums[i] <= 20`
- `1 <= k <= 10^4`
