// Created by Anshul Kumar at 2026/10/08 14:12
// leetgo: dev
// https://leetcode.com/problems/longest-mountain-in-array/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int longestMountain(vector<int> &arr) {
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
      int begin = i;
      int peak = i;
      while (peak < n - 1) {
        if (arr[peak] >= arr[peak + 1])
          break;
        peak++;
      }
      if (peak == begin) {
        continue;
      }
      int end = peak;
      while (end < n - 1) {
        if (arr[end] <= arr[end + 1])
          break;
        end++;
      }
      int size = end - begin + 1;
      if (peak == end)
        continue;
      ans = max(ans, size);
      i = end - 1;
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  try {
    vector<int> arr = LeetCodeIO::deserialize<vector<int>>(cin);

    Solution obj;
    auto res = obj.longestMountain(arr);

    stringstream out_stream;
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << '\n';
  } catch (const LeetCodeIO::Error &error) {
    cerr << "LC_IO: " << error.what() << '\n';
    return 2;
  }
  return 0;
}
