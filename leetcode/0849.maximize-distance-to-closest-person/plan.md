---
judge: leetcode
id: "849"
title: "Maximize Distance to Closest Person"
url: https://leetcode.com/problems/maximize-distance-to
difficulty: Medium
tags: [array]
status: solved
started: 2026-10-09
solved: 2026-10-09
---

# 849. Maximize Distance to Closest Person

[Problem](https://leetcode.com/problems/maximize-distance-to)

## Understanding

- The problem is simply asking us to find for a given index whats its closest distance to any other index with value 1, and out of all the indexes the answer is the max value.

## Approach (Before Coding)

- Simply so 2 passes of the array (forward and backward)
- In each pass, maintain the most updated position of index with value 1, called `seat`, and for each index where value is 0 calculate its distance from the closest seat found so far, `dist[i] = abs(i - seat)`;
- for each index its minimum distance is the minimum of the both the passes;
- In end simply return the max so far

## Complexity

- Time: `O(n)`
- Space: `O(n) can be compressed to O(1) is using the original array itself`

## Edge Cases

- none

## Mistake / Struggle

- none

## Reuse Trigger

- none

## Sketch

![sketch](sketch.excalidraw.svg)
