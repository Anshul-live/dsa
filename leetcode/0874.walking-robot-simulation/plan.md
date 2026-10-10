---
judge: leetcode
id: "874"
title: "Walking Robot Simulation"
url: https://leetcode.com/problems/walking-robot-simula
difficulty: Medium
tags: [array, hash-table, simulation]
status: solved
started: 2026-10-10
solved: 2026-10-10
---

# 874. Walking Robot Simulation

[Problem](https://leetcode.com/problems/walking-robot-simula)

## Understanding

- Simple simulation

## Approach (Before Coding)

- Just Maintain A robot object (x, y, dir) and then according to commands simulate movement while tracking whether a object is hit or not;

## Complexity

- Time: `O(obstacles)`
- Space: `O(obstacles)`

## Edge Cases

-

## Mistake / Struggle

- Not properly reading the problem , resulting in wrong values calculation (like Euclidean instead of squared Euclidean)
- Checking Non needed case resulting in wrong algorithm

## Reuse Trigger

- None

## Sketch

![sketch](sketch.excalidraw.svg)
