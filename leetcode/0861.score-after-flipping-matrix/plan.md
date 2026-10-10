---
judge: leetcode
id: "861"
title: "Score After Flipping Matrix"
url: https://leetcode.com/problems/score-after-flipping
difficulty: Medium
tags: [array, greedy, bit-manipulation, matrix]
status: solved
started: 2026-10-10
solved: 2026-10-10
---

# 861. Score After Flipping Matrix

[Problem](https://leetcode.com/problems/score-after-flipping)

## Understanding

-

## Approach (Before Coding)

- Flip rows too ensure all bits in first col are 1, then for rest cols flip cols if number of 1's is less than half the size of col.
- then sum the numbers

## Complexity

- Time: `O(n * m)`
- Space: `O(1)`

## Edge Cases

-

## Mistake / Struggle

- Wrongfully calculating the size of column in flip_col.
- Using `n / 2` instead of `m / 2` in count comparison.

## Reuse Trigger

-

## Sketch

![sketch](sketch.excalidraw.svg)
