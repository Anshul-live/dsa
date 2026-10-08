// Created by Anshul Kumar at 2026/10/08 13:48
// leetgo: dev
// https://leetcode.com/problems/max-increase-to-keep-city-skyline/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
    int n = grid[0].size();
    vector<int> row_max(n);
    vector<int> col_max(n);

    for (int i = 0; i < n; i++) {
      int max_in_row = INT_MIN;
      int max_in_col = INT_MIN;
      for (int j = 0; j < n; j++) {
        max_in_row = max(max_in_row, grid[i][j]);
        max_in_col = max(max_in_col, grid[j][i]);
      }
      row_max[i] = max_in_row;
      col_max[i] = max_in_col;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ans += (min(row_max[i], col_max[j]) - grid[i][j]);
      }
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  try {
    vector<vector<int>> grid =
        LeetCodeIO::deserialize<vector<vector<int>>>(cin);

    Solution obj;
    auto res = obj.maxIncreaseKeepingSkyline(grid);

    stringstream out_stream;
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << '\n';
  } catch (const LeetCodeIO::Error &error) {
    cerr << "LC_IO: " << error.what() << '\n';
    return 2;
  }
  return 0;
}
