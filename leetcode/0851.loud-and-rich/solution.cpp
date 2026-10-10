// Created by Anshul Kumar at 2026/10/10 12:27
// leetgo: dev
// https://leetcode.com/problems/loud-and-rich/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int help(vector<vector<int>> &adj, int i, vector<int> &quiet,
           vector<int> &ans) {
    int res = i;
    if (ans[i] != -1)
      return ans[i];
    for (auto j : adj[i]) {
      int temp = help(adj, j, quiet, ans);
      if (quiet[temp] < quiet[res]) {
        res = temp;
      }
    }
    return ans[i] = res;
  }
  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {

    int n = quiet.size();
    vector<vector<int>> adj(n);
    vector<int> ans(n, -1);

    for (auto &r : richer) {
      int u = r[1];
      int v = r[0];
      adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
      help(adj, i, quiet, ans);
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  try {
    vector<vector<int>> richer =
        LeetCodeIO::deserialize<vector<vector<int>>>(cin);
    vector<int> quiet = LeetCodeIO::deserialize<vector<int>>(cin);

    Solution obj;
    auto res = obj.loudAndRich(richer, quiet);

    stringstream out_stream;
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << '\n';
  } catch (const LeetCodeIO::Error &error) {
    cerr << "LC_IO: " << error.what() << '\n';
    return 2;
  }
  return 0;
}
