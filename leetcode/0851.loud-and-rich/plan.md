---
judge: leetcode
id: "851"
title: "Loud and Rich"
url: https://leetcode.com/problems/loud-and-rich/
difficulty: Medium
tags: [array, depth-first-search, graph, topological-sort]
status: solved
started: 2026-10-10
solved: 2026-10-10
---
# 851. Loud and Rich

[Problem](https://leetcode.com/problems/loud-and-rich/)

## Understanding
- In simple terms , this is a DAG (Directed Acyclic Graph), for each node we have to find the most quiet node among all nodes reachable from it including itself.

## Approach (Before Coding)
- Just BFS/DFS the graph and for each node find the quitest among all its children and itself.

## Complexity
- Time: `O(V + E)`
- Space: `O(V + E)`

## Edge Cases
-

## Mistake / Struggle
- i accidentally didn't pass the var `i` in the final for loop in loudAndRich func instead passed 0, causing non traversal of complete graph.

## Reuse Trigger
- relationships , graph like structure

## Sketch
![sketch](sketch.excalidraw.svg)
