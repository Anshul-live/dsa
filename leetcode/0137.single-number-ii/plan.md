---
judge: leetcode
id: "137"
title: "Single Number II"
url: https://leetcode.com/problems/single-number-ii/
difficulty: Medium
tags: [array, bit-manipulation]
status: todo
started: 2026-10-07
solved:
---

# 137. Single Number II

[Problem](https://leetcode.com/problems/single-number-ii/)

## Understanding

- The problem asks for finding the number that appears exactly once. In constant space.

## Approach (Before Coding)

- Naive method uses sorting (nlogn) or hashmap (n space and n time).
- but we can optimise by instead using a fixed array of size 32 each element representing a bit position.
- The observation is if we count the numbers of elements for which that specific bit is active, its wither (3*x) (if only the numbers that appear thrice contribute to it) or (3*x + 1) (if the unique number also contributes to it) x >= 0 <= n - 2.

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Edge Cases

- negative numbers
- INT_MIN causing out of bound on naive bit counting instead of fixed 3
  2 bit counting loop

## Mistake / Struggle

- Not handling the negative number case
- Mismanaging Negative Numbers not realising that setting the 31 bit of a int itself encodes the negative sign so no need of explicit tracking of negative sign

## Reuse Trigger

- Constant Space
- Array

## Sketch

![sketch](sketch.excalidraw.svg)
