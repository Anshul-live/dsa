// Created by Anshul Kumar at 2026/10/10 13:22
// leetgo: dev
// https://leetcode.com/problems/score-after-flipping-matrix/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
    int convert(vector<int> &row) {
    int ans = 0;
    for (int i : row) {
      ans <<= 1;
      ans |= i;
    }
    return ans;
  }
  void flip_row(vector<vector<int>> &grid, int row) {
    int n = grid[row].size();
    for (int i = 0; i < n; i++) {
      grid[row][i] = grid[row][i] == 1 ? 0 : 1;
    }
  }
  void flip_col(vector<vector<int>> &grid, int col) {
    int n = grid.size();
    for (int i = 0; i < n; i++) {
      grid[i][col] = grid[i][col] == 1 ? 0 : 1;
    }
  }
  int matrixScore(vector<vector<int>> &grid) {

    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++) {
      if (grid[i][0] == 0)
        flip_row(grid, i);
    }

    for (int i = 1; i < n; i++) {
      int count = 0;
      for (int j = 0; j < m; j++) {
        count += grid[j][i];
      }

      if (count <= m / 2)
        flip_col(grid, i);
    }

    int sum = 0;

    for (auto &row : grid) {
      sum += convert(row);
    }
    return sum;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  try {
    vector<vector<int>> grid =
        LeetCodeIO::deserialize<vector<vector<int>>>(cin);

    Solution obj;
    auto res = obj.matrixScore(grid);

    stringstream out_stream;
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << '\n';
  } catch (const LeetCodeIO::Error &error) {
    cerr << "LC_IO: " << error.what() << '\n';
    return 2;
  }
  return 0;
}
