// Created by Anshul Kumar at 2026/10/07 10:11
// leetgo: dev
// https://leetcode.com/problems/construct-quad-tree/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
public:
  Node *helper(vector<vector<int>> &grid, int x, int y, int size) {
    if (size == 0)
      return nullptr;
    if (size == 1) {
      int val = grid[x][y];
      Node *newnode = new Node();
      if (val == 1) {
        newnode->val = true;
      } else {
        newnode->val = false;
      }
      return newnode;
    }

    int one_count = 0;
    ;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (arr[i + x][j + y] == 1)
          one_count++;
      }
    }

    Node *newnode = new Node();

    if (one_count == (size * size)) {
      newnode->val = true;
    } else if (one_count == 0) {
      newnode->val = false;
    } else {
      int move = size / 2;
      newnode->topLeft = helper(grid, x, y, move);
      newnode->topRight = helper(grid, x, y + move, move);
      newnode->bottomLeft = helper(grid, x + move, y, move);
      newnode->bottomRight = helper(grid, x + move, y + move, move);
    }

    return newnode;
  }
  Node *construct(vector<vector<int>> &grid) {
    return helper(grid, 0, 0, grid.size());
  }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
  ios_base::sync_with_stdio(false);
  try {
    vector<vector<int>> grid =
        LeetCodeIO::deserialize<vector<vector<int>>>(cin);

    Solution obj;
    auto res = obj.construct(grid);

    stringstream out_stream;
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << '\n';
  } catch (const LeetCodeIO::Error &error) {
    cerr << "LC_IO: " << error.what() << '\n';
    return 2;
  }
  return 0;
}
