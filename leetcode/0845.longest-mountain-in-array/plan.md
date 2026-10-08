---
judge: leetcode
id: "845"
title: "Longest Mountain in Array"
url: https://leetcode.com/problems/longest-mountain-in-
difficulty: Medium
tags: [array, two-pointers, dynamic-programming, enumerat]
status: solved
started: 2026-10-08
solved: 2026-10-08
---

# 845. Longest Mountain in Array

[Problem](https://leetcode.com/problems/longest-mountain-in-)

## Understanding

- The problem is simply asking the longest subarray such that first half is strictly increasing then strictly decreasing.

## Approach (Before Coding)

- naive method is to simply find the largest increasing sequence ending at i and decreasing sequence beginning at `i`, then sum the lengths - 1;
- an optimisation of this approach is knowing everything that's part of the sequence of another mountain will itself not be a candidate for a mountain, so skip those,
- The optimised solution builds on this approach only, by starting with a anchor `begin` marking beginning of a mountain finding the `peak` (increasing part end) then find the `end` (decreasing part end) then calculating the size , skipping till the end as its the new anchor for the next mountain candidate

`size` = `end` - `begin` + 1;
`ans` = `max(ans, size)`

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Edge Cases

- `begin` , `peak` and `end` (either two or all three having same value after the pass) , invalidate this mountain and move to next index.
- `end` if reaches the last position without invalidating the decreasing part will overflow and give +1 the actual size
  so if(`end` == size of array) then `end--`

## Mistake / Struggle

- not handling the edge cases properly
- using the wrong comparison, just increasing or decreasing instead of strictly increasing or decreasing

## Reuse Trigger

- subarray
- mountain
- alternating sequence

## Sketch

![sketch](sketch.excalidraw.svg)
